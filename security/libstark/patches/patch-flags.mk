$NetBSD: patch-flags.mk,v 1.1 2022/04/02 11:31:54 nia Exp $

Honor CFLAGS. Don't attempt to tune to the build machine.

--- flags.mk.orig	2018-12-11 08:57:02.000000000 +0000
+++ flags.mk
@@ -1,3 +1,3 @@
 CC=g++
 CPPFLAGS=-std=c++11
-CFLAGS=-O3 -g -Wall -fmessage-length=0 -fopenmp -maes -msse4 -mtune=native
+CFLAGS+=-Wall -fopenmp -maes -msse4
