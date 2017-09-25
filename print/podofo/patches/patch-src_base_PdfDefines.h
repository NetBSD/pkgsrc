$NetBSD: patch-src_base_PdfDefines.h,v 1.1 2017/09/25 22:26:27 joerg Exp $

Merge r1825.

--- src/base/PdfDefines.h.orig	2017-09-25 13:21:28.667585186 +0000
+++ src/base/PdfDefines.h
@@ -194,7 +194,7 @@ const EPdfWriteMode ePdfWriteMode_Defaul
  *
  * Remember to update PdfVariant::GetDataTypeString() when adding members here.
  */
-enum EPdfDataType PODOFO_ENUM_UINT8 {
+enum EPdfDataType {
     ePdfDataType_Bool,                  /**< Boolean datatype: Accepts the values "true" and "false" */
     ePdfDataType_Number,                /**< Number datatype for integer values */
     ePdfDataType_Real,                  /**< Real datatype for floating point numbers */
