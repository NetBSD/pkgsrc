$NetBSD: patch-gas_config_tc-aarch64.c,v 1.1 2021/10/04 17:54:40 mrg Exp $

Part of:

From def9db5cb2a3e87ceada962a3269367b08dc4846 Mon Sep 17 00:00:00 2001
From: Alex Coplan <alex.coplan@arm.com>
Date: Tue, 6 Oct 2020 15:56:44 +0100
Subject: [PATCH] aarch64: Fix bogus type punning in parse_barrier() [PR26699]

This patch fixes a bogus use of type punning in parse_barrier() which
was causing an assembly failure on big endian LP64 hosts when attempting
to assemble "isb sy" for AArch64.

The type of the entries in aarch64_barrier_opt_hsh is
aarch64_name_value_pair. We were incorrectly casting this to the
locally-defined asm_barrier_opt which has a wider type (on LP64) for the
second member. This happened to work on little-endian hosts but fails on
LP64 big endian.

The fix is to use the correct type in parse_barrier(). This makes the
locally-defined asm_barrier_opt redundant, so remove it.

gas/ChangeLog:

	PR 26699
	* config/tc-aarch64.c (asm_barrier_opt): Delete.
	(parse_barrier): Fix bogus type punning.
	* testsuite/gas/aarch64/system.d: Update disassembly.
	* testsuite/gas/aarch64/system.s: Add isb sy test.

(cherry picked from commit 05cfb0d8cc9b7f8676f5ae55a93642f091d5405f)


--- gas/config/tc-aarch64.c.orig	2019-01-28 07:19:14.000000000 -0800
+++ gas/config/tc-aarch64.c	2021-10-03 16:39:34.086756977 -0700
@@ -253,12 +253,6 @@
 typedef struct
 {
   const char *template;
-  unsigned long value;
-} asm_barrier_opt;
-
-typedef struct
-{
-  const char *template;
   uint32_t value;
 } asm_nzcv;
 
@@ -3893,7 +3887,7 @@
 parse_barrier (char **str)
 {
   char *p, *q;
-  const asm_barrier_opt *o;
+  const struct aarch64_name_value_pair *o;
 
   p = q = *str;
   while (ISALPHA (*q))
