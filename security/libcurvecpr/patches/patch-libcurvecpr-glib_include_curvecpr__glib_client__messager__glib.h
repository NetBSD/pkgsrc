$NetBSD: patch-libcurvecpr-glib_include_curvecpr__glib_client__messager__glib.h,v 1.1 2019/12/22 22:28:54 joerg Exp $

--- libcurvecpr-glib/include/curvecpr_glib/client_messager_glib.h.orig	2019-12-22 17:54:41.079631695 +0000
+++ libcurvecpr-glib/include/curvecpr_glib/client_messager_glib.h
@@ -4,12 +4,11 @@
 #include "messager_glib.h"
 
 #include <curvecpr/block.h>
+#include <curvecpr/bytes.h>
 #include <curvecpr/client.h>
 
 #include <string.h>
 
-#include <sodium/crypto_uint64.h>
-
 struct curvecpr_client_messager_glib;
 
 struct curvecpr_client_messager_glib_ops {
