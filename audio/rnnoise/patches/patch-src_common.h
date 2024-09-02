$NetBSD: patch-src_common.h,v 1.1 2024/09/02 16:04:24 nia Exp $

From: "Timothy B. Terriberry" <tterribe@xiph.org>
Date: Mon, 15 Apr 2024 11:27:25 -0700
Subject: [PATCH] Fix compilation errors.

vec_avx.h needs x86cpu.h, and x86cpu.h needs to detect SSE2 (or
 greater) without the Opus macros.
Also, nobody was defining OPUS_CLEAR (but several things were
 including the non-existent os_support.h where it is defined in
 libopus), so replace those calls with RNN_CLEAR and remove the
 erroneous includes.
Take the opportunity to hoist OPUS_GNUC_PREREQ to common.h, too,
 since it is needed in multiple places now.

--- src/common.h.orig	2024-04-15 01:07:37.000000000 +0000
+++ src/common.h
@@ -43,6 +43,14 @@ static RNN_INLINE void rnnoise_free (voi
 #define RNN_CLEAR(dst, n) (memset((dst), 0, (n)*sizeof(*(dst))))
 #endif
 
+# if !defined(OPUS_GNUC_PREREQ)
+#  if defined(__GNUC__)&&defined(__GNUC_MINOR__)
+#   define OPUS_GNUC_PREREQ(_maj,_min) \
+ ((__GNUC__<<16)+__GNUC_MINOR__>=((_maj)<<16)+(_min))
+#  else
+#   define OPUS_GNUC_PREREQ(_maj,_min) 0
+#  endif
+# endif
 
 
 #endif
