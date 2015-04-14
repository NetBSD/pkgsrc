$NetBSD: patch-src_gd__gif__in.c,v 1.1.2.2 2015/04/14 18:19:23 bsiegert Exp $

CVE-2014-9709
https://bitbucket.org/libgd/gd-libgd/commits/47eb44b2e90ca88a08dca9f9a1aa9041e9587f43/raw/

From 47eb44b2e90ca88a08dca9f9a1aa9041e9587f43 Mon Sep 17 00:00:00 2001
From: Remi Collet <fedora@famillecollet.com>
Date: Sat, 13 Dec 2014 08:48:18 +0100
Subject: [PATCH] Fix possible buffer read overflow detected by
 -fsanitize=address, thanks to Jan Bee

---
 src/gd_gif_in.c | 11 +++++++++--
 1 file changed, 9 insertions(+), 2 deletions(-)

diff --git a/src/gd_gif_in.c b/src/gd_gif_in.c
index b3b4ca3..13a663c 100644
--- src/gd_gif_in.c
+++ src/gd_gif_in.c
@@ -75,8 +75,10 @@ static struct {
 
 #define STACK_SIZE ((1<<(MAX_LWZ_BITS))*2)
 
+#define CSD_BUF_SIZE 280
+
 typedef struct {
-	unsigned char buf[280];
+	unsigned char buf[CSD_BUF_SIZE];
 	int curbit;
 	int lastbit;
 	int done;
@@ -468,7 +470,12 @@ GetCode_(gdIOCtx *fd, CODE_STATIC_DATA *scd, int code_size, int flag, int *ZeroD
 
 	ret = 0;
 	for (i = scd->curbit, j = 0; j < code_size; ++i, ++j) {
-		ret |= ((scd->buf[i / 8] & (1 << (i % 8))) != 0) << j;
+		if (i < CSD_BUF_SIZE * 8) {
+			ret |= ((scd->buf[i / 8] & (1 << (i % 8))) != 0) << j;
+		} else {
+			ret = -1;
+			break;
+		}
 	}
 
 	scd->curbit += code_size;
