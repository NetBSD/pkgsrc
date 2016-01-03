$NetBSD: patch-zfuncs.cc,v 1.1 2016/01/03 04:33:50 ryoon Exp $

--- zfuncs.cc.orig	2016-01-01 08:20:29.000000000 +0000
+++ zfuncs.cc
@@ -296,6 +296,7 @@ char *zstrdup(cchar *string, int addcc)
 
 void zmalloc_report()
 {
+#if defined(__linux__)
    using namespace zfuncs;
 
    static double     ptime = 0;
@@ -317,6 +318,7 @@ void zmalloc_report()
    ptime = jobtime();                                                            //  reset some counters
    Nmalloc = Nstrdup = Nfree = 0;
 
+#endif
    return;
 }
 
