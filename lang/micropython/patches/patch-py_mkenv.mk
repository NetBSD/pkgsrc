$NetBSD: patch-py_mkenv.mk,v 1.1 2017/11/29 15:13:32 hauke Exp $

Set the Python's name in pkg Makefile

--- py/mkenv.mk.orig	2017-11-01 00:19:56.000000000 +0000
+++ py/mkenv.mk
@@ -42,7 +42,7 @@ ECHO = @echo
 CP = cp
 MKDIR = mkdir
 SED = sed
-PYTHON = python
+PYTHON ?= python
 
 AS = $(CROSS_COMPILE)as
 CC = $(CROSS_COMPILE)gcc
