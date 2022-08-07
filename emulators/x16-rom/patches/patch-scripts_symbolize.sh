$NetBSD: patch-scripts_symbolize.sh,v 1.1 2022/08/07 17:36:52 thorpej Exp $

Not all systems have bash located in /bin.

--- scripts/symbolize.sh.orig	2022-08-07 00:14:46.188776145 +0000
+++ scripts/symbolize.sh	2022-08-07 00:16:00.740600064 +0000
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/usr/bin/env bash
 
 echo "uint16_t addresses_bank$1[] = {"
 for i in $(cat $2 | sort | uniq | grep "^.....[ABCDEF]" | cut -c 6-9); do
