From 5a93cd6620004a774ccc968894ed341c054f1be1 Mon Sep 17 00:00:00 2001
From: Paul Arthur <paul.arthur@flowerysong.com>
Date: Mon, 16 Apr 2018 14:30:35 +0000
Subject: [PATCH] Fix crash when parsing "c" tags

["/" sig-c-tag-alg] is optional, and even if it weren't we shouldn't
crash when it's not present.
---
 libopenarc/arc-canon.c | 17 +++++++++++++----
 1 file changed, 13 insertions(+), 4 deletions(-)

diff --git a/libopenarc/arc-canon.c b/libopenarc/arc-canon.c
index b2d66b0a..aa0f1453 100644
--- ./libopenarc/arc-canon.c.orig
+++ ./libopenarc/arc-canon.c
@@ -2143,12 +2143,21 @@ arc_parse_canon_t(unsigned char *tag, arc_canon_t *hdr_canon,
 	*hdr_canon = (arc_canon_t) code;
 
 	token = strtok_r(NULL, "/", &last);
-	code = arc_name_to_code(canonicalizations, token);
 
-	if (code == -1)
-		return ARC_STAT_INVALID;
+	if (token == NULL)
+	{
+		/* Per RFC 6376, if no body canonicalization is provided the
+		 * default is simple. */
+		*body_canon = ARC_CANON_SIMPLE;
+	}
+	else
+	{
+		code = arc_name_to_code(canonicalizations, token);
 
-	*body_canon = (arc_canon_t) code;
+		if (code == -1)
+			return ARC_STAT_INVALID;
+		*body_canon = (arc_canon_t) code;
+	}
 
 	return ARC_STAT_OK;
 }
