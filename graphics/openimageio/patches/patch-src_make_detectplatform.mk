$NetBSD: patch-src_make_detectplatform.mk,v 1.1 2014/04/07 12:15:55 ryoon Exp $

--- src/make/detectplatform.mk.orig	2014-04-03 06:08:57.000000000 +0000
+++ src/make/detectplatform.mk
@@ -25,7 +25,9 @@ ifneq (${hw},x86)
   ifneq (${hw},x86_64)
     ifneq (${hw},i386)
       ifneq (${hw},i686)
-        $(error "ERROR: Unknown hardware architecture")
+        ifneq (${hw},amd64)
+          $(error "ERROR: Unknown hardware architecture")
+        endif
       endif
     endif
   endif
@@ -46,6 +48,14 @@ ifeq (${platform},unknown)
     endif
   endif
 
+  # NetBSD
+  ifeq (${uname},netbsd)
+    platform := netbsd
+    ifeq (${hw},amd64)
+      platform := netbsd64
+    endif
+  endif
+
   # Windows
   ifeq (${uname},cygwin)
     platform := windows
