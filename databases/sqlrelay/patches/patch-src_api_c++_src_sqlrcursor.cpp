$NetBSD: patch-src_api_c++_src_sqlrcursor.cpp,v 1.1 2014/05/27 09:55:04 joerg Exp $

--- src/api/c++/src/sqlrcursor.cpp.orig	2014-05-23 16:56:02.000000000 +0000
+++ src/api/c++/src/sqlrcursor.cpp
@@ -4223,10 +4223,10 @@ void sqlrcursor::createFieldLengths() {
 	// 	fieldlengths[1] (corresponding to row 4)
 	uint64_t	rowbuffercount=rowcount-firstrowindex;
 	fieldlengths=new uint32_t *[rowbuffercount+1];
-	fieldlengths[rowbuffercount]=(uint32_t)NULL;
+	fieldlengths[rowbuffercount]=(uint32_t *)NULL;
 	for (uint64_t i=0; i<rowbuffercount; i++) {
 		fieldlengths[i]=new uint32_t[colcount+1];
-		fieldlengths[i][colcount]=(uint32_t)NULL;
+		fieldlengths[i][colcount]=0;
 		for (uint32_t j=0; j<colcount; j++) {
 			fieldlengths[i][j]=getFieldLengthInternal(i,j);
 		}
