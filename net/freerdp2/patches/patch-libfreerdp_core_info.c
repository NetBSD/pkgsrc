$NetBSD: patch-libfreerdp_core_info.c,v 1.1 2024/08/15 20:41:32 markd Exp $

gcc14 (incompatible pointer type)

--- libfreerdp/core/info.c.orig	2024-04-22 09:26:59.000000000 +0000
+++ libfreerdp/core/info.c
@@ -85,7 +85,7 @@ static BOOL rdp_read_info_null_string(co
 
 	if (cbLen > 0)
 	{
-		const WCHAR* domain = Stream_Pointer(s);
+		const WCHAR* domain = (const WCHAR*)Stream_Pointer(s);
 
 		if (isNullTerminated && (max > 0))
 			max -= nullSize;
