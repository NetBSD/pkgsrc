$NetBSD: patch-src_dom_io_domstream.cpp,v 1.1 2012/11/16 00:54:04 joerg Exp $

--- src/dom/io/domstream.cpp.orig	2012-11-15 18:28:52.000000000 +0000
+++ src/dom/io/domstream.cpp
@@ -35,6 +35,7 @@
  */
 
 #include <cstdio>
+#include <cstring>
 #include <math.h>
 #include <stdarg.h>
 
@@ -285,12 +286,11 @@ static int getint(const DOMString &buf, 
 
 
 
-static int dprintf(Writer &outs, const DOMString &fmt, va_list ap)
+static int dprintf(Writer &outs, const char *fmt, va_list ap)
 {
+    size_t len = strlen(fmt);
 
-    int len = fmt.size();
-
-    for (int pos=0 ; pos < len ; pos++)
+    for (size_t pos = 0 ; pos < len ; pos++)
         {
         XMLCh ch = fmt[pos];
 
@@ -909,7 +909,7 @@ Writer &BasicWriter::printf(char const *
     return *this;
 }
 */
-Writer &BasicWriter::printf(const DOMString &fmt, ...)
+Writer &BasicWriter::printf(const char *fmt, ...)
 {
     va_list args;
     va_start(args, fmt);
