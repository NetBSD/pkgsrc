$NetBSD: patch-mk_rt.mk,v 1.3 2017/02/23 09:35:16 jperkin Exp $

Don't build gcc_personality_v0.o on NetBSD.

--- mk/rt.mk.orig	2017-02-09 01:37:48.000000000 +0000
+++ mk/rt.mk
@@ -552,9 +552,11 @@ endif
 ifeq ($$(findstring msvc,$(1)),)
 
 ifeq ($$(findstring freebsd,$(1)),)
+ifeq ($$(findstring netbsd,$(1)),)
 $(call ADD_INTRINSIC,$(1),gcc_personality_v0.o)
 endif
 endif
+endif
 
 ifeq ($$(findstring aarch64,$(1)),aarch64)
 $(foreach intrinsic,comparetf2.o \
