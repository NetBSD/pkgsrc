$NetBSD: patch-src_ft2__sample__ed.c,v 1.2 2019/07/23 08:20:22 fox Exp $

Add the HAS_SSE macro so that build failures do not occur in i386
systems that lack SSE support.

--- src/ft2_sample_ed.c.orig	2019-07-22 16:27:23.010951973 +0000
+++ src/ft2_sample_ed.c
@@ -689,7 +689,7 @@ static void sampleLine(int16_t x1, int16
 
 static void getMinMax16(const void *p, uint32_t scanLen, int16_t *min16, int16_t *max16)
 {
-#if defined __APPLE__ || defined _WIN32 || defined __i386__ || defined __amd64__
+#if defined __APPLE__ || (defined HAS_SSE && (defined _WIN32 || defined __i386)) || defined __amd64__
 	if (cpu.hasSSE2)
 	{
 		/* Taken with permission from the OpenMPT project (and slightly modified).
@@ -775,7 +775,7 @@ static void getMinMax16(const void *p, u
 
 static void getMinMax8(const void *p, uint32_t scanLen, int8_t *min8, int8_t *max8)
 {
-#if defined __APPLE__ || defined _WIN32 || defined __i386__ || defined __amd64__
+#if defined __APPLE__ || (defined HAS_SSE && (defined _WIN32 || defined __i386)) || defined __amd64__
 	if (cpu.hasSSE2)
 	{
 		/* Taken with permission from the OpenMPT project (and slightly modified).
