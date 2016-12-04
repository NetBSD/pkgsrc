$NetBSD: patch-CPP_7zip_Archive_7z_7zIn.cpp,v 1.1.2.2 2016/12/04 15:28:33 bsiegert Exp $

CVE-2016-9296 https://sourceforge.net/p/p7zip/bugs/185/

--- CPP/7zip/Archive/7z/7zIn.cpp.orig	2016-11-30 14:19:04.000000000 +0000
+++ CPP/7zip/Archive/7z/7zIn.cpp
@@ -1097,6 +1097,7 @@ HRESULT CInArchive::ReadAndDecodePackedS
       if (CrcCalc(data, unpackSize) != folders.FolderCRCs.Vals[i])
         ThrowIncorrect();
   }
+if (folders.PackPositions)
   HeadersSize += folders.PackPositions[folders.NumPackStreams];
   return S_OK;
 }
