$NetBSD: patch-libqalculate_Calculator.cc,v 1.1 2021/01/14 11:20:05 jperkin Exp $

Explicitly use std::queue.

--- libqalculate/Calculator.cc.orig	2019-10-22 16:35:55.000000000 +0000
+++ libqalculate/Calculator.cc
@@ -115,6 +115,8 @@ long int usecs, secs, usecs2, usecs3;
 #define ADD_TIME1 gettimeofday(&tvtime, NULL); usecs2 = tvtime.tv_usec - usecs + (tvtime.tv_sec - secs) * 1000000; 
 #define ADD_TIME2 gettimeofday(&tvtime, NULL); usecs3 += tvtime.tv_usec - usecs + (tvtime.tv_sec - secs) * 1000000 - usecs2; */
 
+using std::queue;
+
 typedef void (*CREATEPLUG_PROC)();
 
 PlotParameters::PlotParameters() {
