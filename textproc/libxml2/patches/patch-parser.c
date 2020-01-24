$NetBSD: patch-parser.c,v 1.7 2020/01/24 10:40:36 kim Exp $

Fix CVE-2020-7595

https://gitlab.gnome.org/GNOME/libxml2/commit/0e1a49c89076.patch

From 0e1a49c8907645d2e155f0d89d4d9895ac5112b5 Mon Sep 17 00:00:00 2001
From: Zhipeng Xie <xiezhipeng1@huawei.com>
Date: Thu, 12 Dec 2019 17:30:55 +0800
Subject: [PATCH] Fix infinite loop in xmlStringLenDecodeEntities

When ctxt->instate == XML_PARSER_EOF,xmlParseStringEntityRef
return NULL which cause a infinite loop in xmlStringLenDecodeEntities

Found with libFuzzer.

Signed-off-by: Zhipeng Xie <xiezhipeng1@huawei.com>
---
 parser.c | 3 ++-
 1 file changed, 2 insertions(+), 1 deletion(-)

diff --git a/parser.c b/parser.c
index d1c31963..a34bb6cd 100644
--- parser.c
+++ parser.c
@@ -2646,7 +2646,8 @@ xmlStringLenDecodeEntities(xmlParserCtxtPtr ctxt, const xmlChar *str, int len,
     else
         c = 0;
     while ((c != 0) && (c != end) && /* non input consuming loop */
-	   (c != end2) && (c != end3)) {
+           (c != end2) && (c != end3) &&
+           (ctxt->instate != XML_PARSER_EOF)) {
 
 	if (c == 0) break;
         if ((c == '&') && (str[1] == '#')) {
-- 
2.24.1

