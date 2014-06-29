$NetBSD: patch-src_internal.H,v 1.1 2014/06/29 03:52:47 dholland Exp $

stpcpy seems to be a macro on MacOS.
note that it would probably be better to remove this declaration
entirely (if the host has stpcpy, why are we declaring it?) but
that might create issues and pkgsrc is in a freeze at the moment.

--- src/internal.H~	2008-08-27 13:01:16.000000000 +0000
+++ src/internal.H
@@ -558,5 +558,6 @@ extern void     init_system( void);
 #endif
 
 #if HOST_HAVE_STPCPY
+#undef stpcpy
 extern char *   stpcpy( char * dest, const char * src);
 #endif
