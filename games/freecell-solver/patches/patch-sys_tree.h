$NetBSD: patch-sys_tree.h,v 1.1 2022/05/13 22:52:56 jperkin Exp $

Fix sys/cdefs.h abuse.

--- sys/tree.h.orig	2019-08-08 13:14:20.000000000 +0000
+++ sys/tree.h
@@ -29,7 +29,7 @@
 #pragma once
 
 #include "rinutils/unused.h"
-#ifndef _WIN32
+#if !defined(_WIN32) && !defined(__sun)
 #include <sys/cdefs.h>
 #endif
 
