$NetBSD: patch-src_bmp.c,v 1.1 2017/07/01 22:13:26 joerg Exp $

Fix *print use.

--- src/bmp.c.orig	2017-07-01 21:10:21.915538844 +0000
+++ src/bmp.c
@@ -140,7 +140,7 @@ int write_bmp_header(cups_page_header_t 
 
 int getHalftoneByResolution (PIMAGEHEADER pImage)
 {
-	BYTE szFile[ 256 ];
+	char szFile[ 256 ];
    FILE *fh;
 	size_t numread;
 	PBITMAPFILEHEADER pbmpfh;
@@ -155,7 +155,7 @@ int getHalftoneByResolution (PIMAGEHEADE
 
 	for(plane=startplane; plane <4; plane++) //cmyk 0 1 2 3
 	{
-		sprintf(szFile, 
+		snprintf(szFile, sizeof(szFile),
 			"%s/Halftones/km_ht_%d%d.bmp",
 			KM_DATADIR, pImage->xResolution/1200, plane); 
 		
@@ -171,7 +171,7 @@ int getHalftoneByResolution (PIMAGEHEADE
 		numread = fread(pbmpfh,1,sizeof(BITMAPFILEHEADER),fh);
 		if(numread != sizeof(BITMAPFILEHEADER))
 		{
-			fprintf(stderr, "ERROR: numread=%d, size=%d\n",numread,sizeof(BITMAPFILEHEADER));
+			fprintf(stderr, "ERROR: numread=%zu, size=%zu\n",numread,sizeof(BITMAPFILEHEADER));
 			return CUPS_FALSE;
 		}
 		BMP_ASSIGN_DWORD(pbmpfh->bfSize,pbmpfh->bfSize);
@@ -197,8 +197,8 @@ int getHalftoneByResolution (PIMAGEHEADE
 
 		if(pHTtmp == NULL)
 		{
-			fprintf(stderr, "ERROR: pbih->width=%d,height=%d\n)",pbih->biWidth,pbih->biHeight);
-			fprintf(stderr, "ERROR: size=%d,NULL pHTtmp\n",sizeof(HTHEADER));
+			fprintf(stderr, "ERROR: pbih->width=%lu,height=%lu\n)",(unsigned long)pbih->biWidth,(unsigned long)pbih->biHeight);
+			fprintf(stderr, "ERROR: size=%zu,NULL pHTtmp\n",sizeof(HTHEADER));
 			return CUPS_FALSE;
 		}
 		pHTtmp->wID = plane;// * (objtype+1);
