$NetBSD: patch-src_prcserror.cc,v 1.1 2013/08/31 14:46:20 joerg Exp $

--- src/prcserror.cc.orig	2013-08-31 13:49:17.000000000 +0000
+++ src/prcserror.cc
@@ -108,7 +108,7 @@ int PrettyStreambuf::overflow(int c)
     return 1;
 }
 
-int PrettyStreambuf::xsputn(const char* s0, int n0)
+std::streamsize PrettyStreambuf::xsputn(const char* s0, std::streamsize n0)
 {
     if (dont_print && *dont_print)
 	return n0;
