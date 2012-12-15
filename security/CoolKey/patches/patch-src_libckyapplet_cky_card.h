$NetBSD: patch-src_libckyapplet_cky_card.h,v 1.1 2012/12/15 01:07:17 pettai Exp $

Build fix for a more modern pcsc-lite.

--- src/libckyapplet/cky_card.h.orig	2012-12-11 21:28:32.000000000 +0000
+++ src/libckyapplet/cky_card.h
@@ -41,23 +41,23 @@ CKYLIST_DECLARE(CKYReaderName, char *)
 CKYLIST_DECLARE(CKYCardConnection, CKYCardConnection *)
 
 CKY_BEGIN_PROTOS
-void CKYReader_Init(SCARD_READERSTATE_A *reader);
-void CKYReader_FreeData(SCARD_READERSTATE_A *reader);
+void CKYReader_Init(SCARD_READERSTATE *reader);
+void CKYReader_FreeData(SCARD_READERSTATE *reader);
 
 /*
- * "Accessors": for SCARD_READERSTATE_A structure as a class.
- * These functions take an SCARD_READERSTATE_A which can also be referenced
+ * "Accessors": for SCARD_READERSTATE structure as a class.
+ * These functions take an SCARD_READERSTATE which can also be referenced
  * directly.
  */
-CKYStatus CKYReader_SetReaderName(SCARD_READERSTATE_A *reader, const char *name);
-const char *CKYReader_GetReaderName(const SCARD_READERSTATE_A *reader);
-CKYStatus CKYReader_SetKnownState(SCARD_READERSTATE_A *reader, 
+CKYStatus CKYReader_SetReaderName(SCARD_READERSTATE *reader, const char *name);
+const char *CKYReader_GetReaderName(const SCARD_READERSTATE *reader);
+CKYStatus CKYReader_SetKnownState(SCARD_READERSTATE *reader, 
 						unsigned long state);
-unsigned long CKYReader_GetKnownState(const SCARD_READERSTATE_A *reader);
-unsigned long CKYReader_GetEventState(const SCARD_READERSTATE_A *reader);
-CKYStatus CKYReader_GetATR(const SCARD_READERSTATE_A *reader, CKYBuffer *buf);
+unsigned long CKYReader_GetKnownState(const SCARD_READERSTATE *reader);
+unsigned long CKYReader_GetEventState(const SCARD_READERSTATE *reader);
+CKYStatus CKYReader_GetATR(const SCARD_READERSTATE *reader, CKYBuffer *buf);
 /* create an array of READERSTATEs from a LIST of Readers */
-SCARD_READERSTATE_A *CKYReader_CreateArray(const CKYReaderNameList readerNames, 
+SCARD_READERSTATE *CKYReader_CreateArray(const CKYReaderNameList readerNames, 
 					  unsigned long *readerCount);
 /* frees the reader, then the full array */
 void CKYReader_DestroyArray(SCARD_READERSTATE *reader, unsigned long count);
@@ -88,7 +88,7 @@ CKYStatus CKYCardContext_FindReadersByAT
 				const CKYBuffer *targetATR);
 /* return if any of the readers in our array has changed in status */
 CKYStatus CKYCardContext_WaitForStatusChange(CKYCardContext *context,
-				SCARD_READERSTATE_A *readers,
+				SCARD_READERSTATE *readers,
 				unsigned long readerCount,
 				unsigned long timeout);
 /* cancel any current operation (such as wait for status change) on this
