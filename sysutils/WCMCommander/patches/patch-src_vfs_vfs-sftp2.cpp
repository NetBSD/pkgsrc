$NetBSD: patch-src_vfs_vfs-sftp2.cpp,v 1.1 2024/04/29 09:39:45 nia Exp $

Fix building with modern C++ compilers.
prompts[i].text is unsigned char *.

--- src/vfs/vfs-sftp2.cpp.orig	2024-04-29 09:30:37.929308710 +0000
+++ src/vfs/vfs-sftp2.cpp
@@ -187,7 +187,7 @@ void KbIntCallback(
 		for ( i = 0; i < num_prompts; i++ )
 		{
 			pData[i].visible = prompts[i].echo != 0;
-			pData[i].prompt = std::string( prompts[i].text, prompts[i].length );
+			pData[i].prompt = std::string( reinterpret_cast<char *>(prompts[i].text), prompts[i].length );
 		}
 
 		if ( !kbdIntInfo->Prompt(
