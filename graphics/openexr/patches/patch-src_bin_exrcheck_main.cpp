$NetBSD: patch-src_bin_exrcheck_main.cpp,v 1.1 2023/03/30 20:26:38 joerg Exp $

Needed for uint64_t.

--- src/bin/exrcheck/main.cpp.orig	2022-04-07 00:52:25.000000000 +0000
+++ src/bin/exrcheck/main.cpp
@@ -4,6 +4,7 @@
 #include <ImfCheckFile.h>
 #include <ImathConfig.h>
 
+#include <cstdint>
 #include <iostream>
 #include <fstream>
 #include <string.h>
