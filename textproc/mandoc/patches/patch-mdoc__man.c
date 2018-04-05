$NetBSD: patch-mdoc__man.c,v 1.1 2018/04/05 09:20:52 wiz Exp $

Revision 1.124

For .Do/.Dq, use the documented and portable \(lq and \(rq
character escape sequences rather than the undocumented and
non-portable \(Lq and \(Rq.

--- mdoc_man.c.orig	2017-08-05 12:40:22.000000000 +0000
+++ mdoc_man.c
@@ -202,8 +202,8 @@ static	const struct manact __manacts[MDO
 	{ NULL, pre_bk, post_bk, NULL, NULL }, /* Bx */
 	{ NULL, pre_skip, NULL, NULL, NULL }, /* Db */
 	{ NULL, NULL, NULL, NULL, NULL }, /* Dc */
-	{ cond_body, pre_enc, post_enc, "\\(Lq", "\\(Rq" }, /* Do */
-	{ cond_body, pre_enc, post_enc, "\\(Lq", "\\(Rq" }, /* Dq */
+	{ cond_body, pre_enc, post_enc, "\\(lq", "\\(rq" }, /* Do */
+	{ cond_body, pre_enc, post_enc, "\\(lq", "\\(rq" }, /* Dq */
 	{ NULL, NULL, NULL, NULL, NULL }, /* Ec */
 	{ NULL, NULL, NULL, NULL, NULL }, /* Ef */
 	{ NULL, pre_em, post_font, NULL, NULL }, /* Em */
