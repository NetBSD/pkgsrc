$NetBSD: patch-callback_vacall__r_vacall-x86__64.s,v 1.1 2016/08/26 17:25:08 joerg Exp $

--- callback/vacall_r/vacall-x86_64.s.orig	2016-08-26 15:06:32.092318377 +0000
+++ callback/vacall_r/vacall-x86_64.s
@@ -216,10 +216,12 @@ __vacall_r:
 .LSCIE1:
 	.long	0x0
 	.byte	0x1
-	.string	""
+	.string	"zR"
 	.uleb128 0x1
 	.sleb128 -8
 	.byte	0x10
+	.uleb128 0x1
+	.byte   0x1b
 	.byte	0xc
 	.uleb128 0x7
 	.uleb128 0x8
@@ -231,8 +233,8 @@ __vacall_r:
 	.long	.LEFDE1-.LASFDE1
 .LASFDE1:
 	.long	.LASFDE1-.Lframe1
-	.quad	.LFB1
-	.quad	.LFE1-.LFB1
+	.long	.LFB1-.
+	.long	.LFE1-.LFB1
 	.byte	0x4
 	.long	.LCFI0-.LFB1
 	.byte	0xe
