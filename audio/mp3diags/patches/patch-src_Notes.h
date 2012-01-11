$NetBSD: patch-src_Notes.h,v 1.1 2012/01/11 19:25:08 hans Exp $

--- src/Notes.h.orig	2010-02-13 07:58:04.000000000 +0100
+++ src/Notes.h	2012-01-02 11:26:42.140106730 +0100
@@ -32,6 +32,10 @@
 #include  "SerSupport.h"
 #include  <boost/serialization/split_member.hpp>
 
+#ifdef ERR
+#undef ERR
+#endif
+
 /*
 Stores a message that is added while parsing a file. Multiple messages may be added, depending on the issues found.
 
