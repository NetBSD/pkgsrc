$NetBSD: patch-common_ucnv__io.cpp,v 1.1.2.2 2015/09/30 19:41:25 bsiegert Exp $

Debian CVE-2015-1270.patch

--- common/ucnv_io.cpp.orig	2015-03-27 21:10:42.000000000 +0000
+++ common/ucnv_io.cpp
@@ -744,7 +744,7 @@ ucnv_io_getConverterName(const char *ali
              * the name begins with 'x-'. If it does, strip it off and try
              * again.  This behaviour is similar to how ICU4J does it.
              */
-            if (aliasTmp[0] == 'x' || aliasTmp[1] == '-') {
+            if (aliasTmp[0] == 'x' && aliasTmp[1] == '-') {
                 aliasTmp = aliasTmp+2;
             } else {
                 break;
