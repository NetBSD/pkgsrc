$NetBSD: patch-avcall_avcall-x86__64.s,v 1.1 2016/08/26 17:25:08 joerg Exp $

--- avcall/avcall-x86_64.s.orig	2004-01-25 12:47:15.000000000 +0000
+++ avcall/avcall-x86_64.s
@@ -335,10 +335,12 @@ __builtin_avcall:
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
@@ -350,8 +352,8 @@ __builtin_avcall:
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
