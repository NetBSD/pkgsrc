$NetBSD: patch-pwutil.c,v 1.1 2012/05/03 08:31:05 martin Exp $

# NetBSD uses 64bit time_t, even on 32bit architectures.
# This makes struct passwd require 8 byte-alginement on, for example,
# 32bit sparc. Curiously it all worked out naturally for sparc64 ;-)
# To not add to the magic, let the compiler design proper alignement
# by declaring a helper struct which holds the cache entry header as
# well as struct passwd.

--- pwutil.c.orig	2011-10-21 15:18:38.000000000 +0200
+++ pwutil.c	2012-05-03 10:05:28.000000000 +0200
@@ -84,6 +84,16 @@
 };
 
 /*
+ * To give the compiler a chance to properly align things, we declare this
+ * dummy structure to ease our size/offset calculations.
+ */
+struct cache_and_passwd {
+	struct cache_item cache;
+	struct passwd pw;
+};
+
+
+/*
  * Compare by uid.
  */
 static int
@@ -144,6 +154,7 @@
     size_t nsize, psize, csize, gsize, dsize, ssize, total;
     struct cache_item *item;
     struct passwd *newpw;
+    struct cache_and_passwd *cnp;
 
     /* If shell field is empty, expand to _PATH_BSHELL. */
     pw_shell = (pw->pw_shell == NULL || pw->pw_shell[0] == '\0')
@@ -151,7 +162,7 @@
 
     /* Allocate in one big chunk for easy freeing. */
     nsize = psize = csize = gsize = dsize = ssize = 0;
-    total = sizeof(struct cache_item) + sizeof(struct passwd);
+    total = sizeof(struct cache_and_passwd);
     FIELD_SIZE(pw, pw_name, nsize);
     FIELD_SIZE(pw, pw_passwd, psize);
 #ifdef HAVE_LOGIN_CAP_H
@@ -168,15 +179,15 @@
     /* Allocate space for struct item, struct passwd and the strings. */
     if ((item = malloc(total)) == NULL)
 	    return NULL;
-    cp = (char *) item + sizeof(struct cache_item);
+    cnp = (struct cache_and_passwd*)item;
 
     /*
      * Copy in passwd contents and make strings relative to space
      * at the end of the buffer.
      */
-    newpw = (struct passwd *) cp;
+    newpw = &cnp->pw;
     memcpy(newpw, pw, sizeof(struct passwd));
-    cp += sizeof(struct passwd);
+    cp = (char*)&cnp[1];
     FIELD_COPY(pw, newpw, pw_name, nsize);
     FIELD_COPY(pw, newpw, pw_passwd, psize);
 #ifdef HAVE_LOGIN_CAP_H
