$NetBSD: patch-src_v6__loadfile.cxx,v 1.1 2016/09/28 10:00:27 kamil Exp $

Handle BSDs.

--- src/v6_loadfile.cxx.orig	2007-03-15 17:59:30.000000000 +0000
+++ src/v6_loadfile.cxx
@@ -2494,7 +2494,7 @@ char* G__tmpnam(char *name)
   G__tmpfiles.Add(name);
   return(name);
 
-#elif /*defined(G__NEVER) && */ ((__GNUC__>=3)||((__GNUC__>=2)&&(__GNUC_MINOR__>=96)))&&(defined(__linux)||defined(__linux__))
+#elif /*defined(G__NEVER) && */ ((__GNUC__>=3)||((__GNUC__>=2)&&(__GNUC_MINOR__>=96)))&&(defined(__linux)||defined(__linux__)||defined(__NetBSD__)||defined(__FreeBSD__)||defined(__OpenBSD__)||defined(__DragonFly__))
   /* After all, mkstemp creates more problem than a solution. */
   static char tempname[G__MAXFILENAME];
   const char *appendix="_cint";
