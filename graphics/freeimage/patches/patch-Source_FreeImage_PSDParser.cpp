$NetBSD: patch-Source_FreeImage_PSDParser.cpp,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- Source/FreeImage/PSDParser.cpp.orig	2016-02-11 04:18:02.000000000 +0000
+++ Source/FreeImage/PSDParser.cpp
@@ -133,8 +133,8 @@ public:
 template <>
 class PSDGetValue<8> {
 public:
-	static inline UINT64 get(const BYTE * iprBuffer) {
-		UINT64 v = ((const UINT64*)iprBuffer)[0];
+	static inline uint64_t get(const BYTE * iprBuffer) {
+		uint64_t v = ((const uint64_t*)iprBuffer)[0];
 #ifndef FREEIMAGE_BIGENDIAN
 		SwapInt64(&v);
 #endif
@@ -147,7 +147,7 @@ public:
 
 // --------------------------------------------------------------------------
 
-static UINT64
+static uint64_t
 psdReadSize(FreeImageIO *io, fi_handle handle, const psdHeaderInfo& header) {
 	if(header._Version == 1) {
 		BYTE Length[4];
@@ -199,11 +199,11 @@ public:
 template <>
 class PSDSetValue<8> {
 public:
-	static inline void set(const BYTE * iprBuffer, UINT64 v) {
+	static inline void set(const BYTE * iprBuffer, uint64_t v) {
 #ifndef FREEIMAGE_BIGENDIAN
 		SwapInt64(&v);
 #endif
-		((UINT64*)iprBuffer)[0] = v;
+		((uint64_t*)iprBuffer)[0] = v;
 	}
 };
 
@@ -213,7 +213,7 @@ public:
 // --------------------------------------------------------------------------
 
 static inline bool
-psdWriteSize(FreeImageIO *io, fi_handle handle, const psdHeaderInfo& header, UINT64 v) {
+psdWriteSize(FreeImageIO *io, fi_handle handle, const psdHeaderInfo& header, uint64_t v) {
 	if(header._Version == 1) {
 		BYTE Length[4];
 		psdSetLongValue(Length, sizeof(Length), (DWORD)v);
@@ -1063,10 +1063,10 @@ unsigned psdParser::GetChannelOffset(FIB
 bool psdParser::ReadLayerAndMaskInfoSection(FreeImageIO *io, fi_handle handle)	{
 	bool bSuccess = true;
 
-	UINT64 nTotalBytes = psdReadSize(io, handle, _headerInfo);
+	uint64_t nTotalBytes = psdReadSize(io, handle, _headerInfo);
 
 	// Hack to handle large PSB files without using fseeko().
-	if (sizeof(long) < sizeof(UINT64)) {
+	if (sizeof(long) < sizeof(uint64_t)) {
 		const long offset = 0x10000000;
 		while (nTotalBytes > offset) {
 			if (io->seek_proc(handle, offset, SEEK_CUR) != 0) {
@@ -1672,7 +1672,7 @@ bool psdParser::WriteLayerAndMaskInfoSec
 	// Short section with no layers.
 	BYTE IntValue[4];
 
-	UINT64 size;
+	uint64_t size;
 	if(_headerInfo._Version == 1) {
 		size = 8;
 	} else {
