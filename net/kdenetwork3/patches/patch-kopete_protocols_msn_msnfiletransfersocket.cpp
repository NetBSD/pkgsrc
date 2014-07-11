$NetBSD: patch-kopete_protocols_msn_msnfiletransfersocket.cpp,v 1.1 2014/07/11 20:06:20 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- kopete/protocols/msn/msnfiletransfersocket.cpp.orig	2005-09-10 08:20:25.000000000 +0000
+++ kopete/protocols/msn/msnfiletransfersocket.cpp
@@ -300,8 +300,8 @@ void MSNFileTransferSocket::slotSendFile
 //		char i2= (char)floor( bytesRead / 256 ) ;
 //		kdDebug(14140) << "MSNFileTransferSocket::slotSendFile: " << (int)i1 <<" + 256* "<< (int)i2 <<" = " << bytesRead <<endl;
 		block[0]='\0';
-		block[1]= (char)fmod( bytesRead, 256 );
-		block[2]= (char)floor( bytesRead / 256 );
+		block[1]= (char)fmod( (float)bytesRead, 256 );
+		block[2]= (char)floor( (float)bytesRead / 256 );
 
 		for (  int f = 0; f < bytesRead; f++ )
 		{
