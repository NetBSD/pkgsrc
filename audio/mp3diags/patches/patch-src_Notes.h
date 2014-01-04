$NetBSD: patch-src_Notes.h,v 1.2 2014/01/04 15:11:43 wiz Exp $

http://sourceforge.net/p/mp3diags/code/279/

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
 
