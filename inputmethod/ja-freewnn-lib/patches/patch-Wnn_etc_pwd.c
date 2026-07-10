$NetBSD: patch-Wnn_etc_pwd.c,v 1.1 2026/07/10 23:32:37 tsutsui Exp $

- Include <time.h> unconditionally for time(3)

--- Wnn/etc/pwd.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/etc/pwd.c
@@ -36,6 +36,8 @@
 #  include <config.h>
 #endif
 
+#include <time.h>
+
 #ifndef JS
 #include <stdio.h>
 #if STDC_HEADERS
@@ -46,7 +48,6 @@
 #if HAVE_UNISTD_H
 #  include <unistd.h>
 #endif
-#include <time.h>
 
 #include "commonhd.h"
 #include "jslib.h"
