$NetBSD: patch-src_od-fs_bsdsocket__posix.cpp,v 1.1 2015/11/04 21:24:14 adam Exp $

u_int8_t * won't automagically become const char *.

--- src/od-fs/bsdsocket_posix.cpp.orig	2014-09-23 10:39:54.000000000 +0000
+++ src/od-fs/bsdsocket_posix.cpp
@@ -928,7 +928,7 @@ static void *bsdlib_threadfunc (void *ar
         break;
 
         case 7: {
-        struct hostent *tmphostent = gethostbyaddr (get_real_address (sb->name), sb->a_addrlen, sb->flags);
+        struct hostent *tmphostent = gethostbyaddr ((const char *)get_real_address (sb->name), sb->a_addrlen, sb->flags);
 
         if (tmphostent) {
             copyHostent (tmphostent, sb);
