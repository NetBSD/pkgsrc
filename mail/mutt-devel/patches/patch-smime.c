$NetBSD: patch-smime.c,v 1.1 2013/03/06 20:17:43 is Exp $

Index: smime.c
===================================================================
--- smime.c	(revision 6178)
+++ smime.c	(revision 6298)
@@ -358,5 +358,5 @@
   FILE *index;
   char buf[LONG_STRING];
-  char fields[5][STRING];
+  char fields[5][STRING+1]; /* +1 due to use of fscanf() below. the max field width does not include the null terminator (see http://dev.mutt.org/trac/ticket/3636) */
   int numFields, hash_suffix, done, cur; /* The current entry */
   MUTTMENU* menu;
@@ -471,5 +471,5 @@
   char cert_path[_POSIX_PATH_MAX];
   char buf[LONG_STRING], prompt[STRING];
-  char fields[5][STRING];
+  char fields[5][STRING+1]; /* +1 due to use of fscanf() below. the max field width does not include the null terminator (see http://dev.mutt.org/trac/ticket/3636) */
   char key[STRING];  
   int numFields;
