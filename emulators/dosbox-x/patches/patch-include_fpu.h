$NetBSD: patch-include_fpu.h,v 1.1 2025/05/16 21:46:43 nia Exp $

From 97bca6f3df2ca4f59aea289ab7038dfecabcffca Mon Sep 17 00:00:00 2001
From: nia <nia@NetBSD.org>
Date: Fri, 16 May 2025 16:12:03 +0200
Subject: [PATCH] Fix big-endian build

Some new members were added to the MMX_reg union, but only
for little endian. Add them to the big endian one too.

Signed-off-by: Nia Alarie <nia@NetBSD.org>

--- include/fpu.h.orig	2022-09-01 22:55:29.000000000 +0000
+++ include/fpu.h
@@ -168,6 +168,10 @@ union alignas(8) MMX_reg {
 	} uw;
 	static_assert(sizeof(uw) == 8, "MMX packing error");
 
+	uint8_t uba[8];
+	uint16_t uwa[4];
+	uint32_t uda[2];
+
 	struct {
 		uint16_t w3,w2,w1,w0;
 	} sw;
