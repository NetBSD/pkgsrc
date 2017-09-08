$NetBSD: patch-lib_generate_stubs.sh,v 1.1 2017/09/08 13:19:34 jaapb Exp $

Use correct path for bash
--- lib/generate_stubs.sh.orig	2017-06-22 04:36:10.000000000 +0000
+++ lib/generate_stubs.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/usr/pkg/bin/bash
 
 set -e -u -o pipefail
 shopt -s extglob
