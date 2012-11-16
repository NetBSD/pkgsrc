$NetBSD: patch-src_dom_io_domstream.h,v 1.1 2012/11/16 00:54:05 joerg Exp $

--- src/dom/io/domstream.h.orig	2012-11-15 18:28:31.000000000 +0000
+++ src/dom/io/domstream.h
@@ -492,7 +492,7 @@ public:
     virtual int put(XMLCh ch) = 0;
 
     /* Formatted output */
-    virtual Writer& printf(const DOMString &fmt, ...) = 0;
+    virtual Writer& printf(const char *fmt, ...) = 0;
 
     virtual Writer& writeChar(char val) = 0;
 
@@ -544,7 +544,7 @@ public:
 
 
     /* Formatted output */
-    virtual Writer &printf(const DOMString &fmt, ...);
+    virtual Writer &printf(const char *fmt, ...);
 
     virtual Writer& writeChar(char val);
 
