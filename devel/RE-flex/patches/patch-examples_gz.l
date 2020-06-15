$NetBSD: patch-examples_gz.l,v 1.1 2020/06/15 15:11:50 scole Exp $

include unistd.h for dup()

--- examples/gz.l.orig	2020-05-25 23:34:27.000000000 +0000
+++ examples/gz.l
@@ -10,6 +10,7 @@
 #include <streambuf>
 #include <cstring>
 #include <zlib.h>
+#include <unistd.h>
 
 #ifndef Z_BUF_LEN
 #define Z_BUF_LEN (65536)
