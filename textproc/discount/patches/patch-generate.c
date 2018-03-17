$NetBSD: patch-generate.c,v 1.1 2018/03/17 20:54:06 schmonz Exp $

Fix self-tests on NetBSD.

--- generate.c.orig	2018-03-02 22:52:05.000000000 +0000
+++ generate.c
@@ -1151,7 +1151,7 @@ islike(MMIOT *f, char *s)
     }
 
     for (i=1; i < len; i++)
-	if (tolower(peek(f,i)) != s[i])
+	if (tolower((unsigned char)peek(f,i)) != s[i])
 	    return 0;
     return 1;
 }
@@ -1269,7 +1269,7 @@ tickhandler(MMIOT *f, int tickchar, int 
     int endticks, size;
     int tick = nrticks(0, tickchar, f);
 
-    if ( !allow_space && isspace(peek(f,tick)) )
+    if ( !allow_space && isspace((unsigned char)peek(f,tick)) )
 	return 0;
 
     if ( (tick >= minticks) && (size = matchticks(f,tickchar,tick,&endticks)) ) {
@@ -1297,7 +1297,7 @@ text(MMIOT *f)
     int smartyflags = 0;
 
     while (1) {
-        if ( (f->flags & MKD_AUTOLINK) && isalpha(peek(f,1)) && !tag_text(f) )
+        if ( (f->flags & MKD_AUTOLINK) && isalpha((unsigned char)peek(f,1)) && !tag_text(f) )
 	    maybe_autolink(f);
 
         c = pull(f);
