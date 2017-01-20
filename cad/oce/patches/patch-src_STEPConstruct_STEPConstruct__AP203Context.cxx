$NetBSD: patch-src_STEPConstruct_STEPConstruct__AP203Context.cxx,v 1.1 2017/01/20 11:00:50 fhajny Exp $

On fbsd + clang we get:
error: cast from 'char* (*)(int, int)' to 'Standard_Integer' loses precision

Fix taken from
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=131600

--- src/STEPConstruct/STEPConstruct_AP203Context.cxx.orig	2017-01-13 05:34:36.000000000 +0000
+++ src/STEPConstruct/STEPConstruct_AP203Context.cxx
@@ -105,6 +105,13 @@ Handle(StepBasic_DateAndTime) STEPConstr
 
     Handle(StepBasic_CoordinatedUniversalTimeOffset) zone = 
       new StepBasic_CoordinatedUniversalTimeOffset;
+#if defined(__FreeBSD__)
+    struct tm newtime;
+    time_t ltime;
+    ltime = time(&ltime);
+    localtime_r(&ltime, &newtime);
+    int timezone = newtime.tm_gmtoff;
+#endif
   #if defined(_MSC_VER) && _MSC_VER >= 1600
     long shift = 0;
     _get_timezone (&shift);
