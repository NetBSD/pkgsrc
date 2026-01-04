$NetBSD: patch-Logger.h,v 1.1 2026/01/04 11:52:20 wiz Exp $

Add missing headers for time and pthread functions.

--- Logger.h.orig	2026-01-04 11:50:09.479246044 +0000
+++ Logger.h
@@ -6,6 +6,8 @@
 #pragma once
 #include <string>
 #include <stdio.h>
+#include <sys/time.h>
+#include <pthread.h>
 #include <cstdarg>
 #include "LogTypes.h"
 
