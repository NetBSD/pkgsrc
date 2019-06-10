$NetBSD: patch-generate.c,v 1.3 2019/06/10 13:32:56 schmonz Exp $

Fix self-tests on NetBSD.

--- generate.c.orig	2019-04-15 15:28:20.000000000 +0000
+++ generate.c
@@ -757,7 +757,7 @@ linkylinky(int image, MMIOT *f)
 	else {
 	    int goodlink, implicit_mark = mmiottell(f);
 
-	    if ( isspace(peek(f,1)) )
+	    if ( isspace((unsigned char)peek(f,1)) )
 		pull(f);
 	    
 	    if ( peek(f,1) == '[' ) {
@@ -1161,7 +1161,7 @@ islike(MMIOT *f, char *s)
     }
 
     for (i=1; i < len; i++)
-	if (tolower(peek(f,i)) != s[i])
+	if (tolower((unsigned char)peek(f,i)) != s[i])
 	    return 0;
     return 1;
 }
@@ -1281,7 +1281,7 @@ tickhandler(MMIOT *f, int tickchar, int 
     int endticks, size;
     int tick = nrticks(0, tickchar, f);
 
-    if ( !allow_space && isspace(peek(f,tick)) )
+    if ( !allow_space && isspace((unsigned char)peek(f,tick)) )
 	return 0;
 
     if ( (tick >= minticks) && (size = matchticks(f,tickchar,tick,&endticks)) ) {
@@ -1309,7 +1309,7 @@ text(MMIOT *f)
     int smartyflags = 0;
 
     while (1) {
-        if ( is_flag_set(f->flags, MKD_AUTOLINK) && isalpha(peek(f,1)) && !tag_text(f) )
+        if ( is_flag_set(f->flags, MKD_AUTOLINK) && isalpha((unsigned char)peek(f,1)) && !tag_text(f) )
 	    maybe_autolink(f);
 
         c = pull(f);
