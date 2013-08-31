$NetBSD: patch-src_include_prcserror.h,v 1.1 2013/08/31 14:46:20 joerg Exp $

--- src/include/prcserror.h.orig	2013-08-31 13:48:53.000000000 +0000
+++ src/include/prcserror.h
@@ -295,7 +295,7 @@ public:
 
 protected:
 
-    virtual int xsputn(const char* s, int n);
+    virtual std::streamsize xsputn(const char* s, std::streamsize n);
     virtual int overflow(int c = EOF);
     virtual int sync();
 
