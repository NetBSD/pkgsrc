$NetBSD: patch-src_utils_SerializeBuffer.cc,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/utils/SerializeBuffer.cc.orig	2013-09-20 13:40:59.000000000 +0000
+++ src/utils/SerializeBuffer.cc
@@ -21,7 +21,7 @@ OutputBuffer::~OutputBuffer()
 }
 
 #ifdef __GNUC__
-template<unsigned LEN> void OutputBuffer::insertN(const void* __restrict data) __restrict
+template<unsigned LEN> void OutputBuffer::insertN(const void* data)
 {
 	byte* newEnd = end + LEN;
 	if (likely(newEnd <= finish)) {
@@ -32,13 +32,13 @@ template<unsigned LEN> void OutputBuffer
 	}
 }
 // Force template instantiation
-template void OutputBuffer::insertN<1>(const void* __restrict data) __restrict;
-template void OutputBuffer::insertN<2>(const void* __restrict data) __restrict;
-template void OutputBuffer::insertN<4>(const void* __restrict data) __restrict;
-template void OutputBuffer::insertN<8>(const void* __restrict data) __restrict;
+template void OutputBuffer::insertN<1>(const void* data);
+template void OutputBuffer::insertN<2>(const void* data);
+template void OutputBuffer::insertN<4>(const void* data);
+template void OutputBuffer::insertN<8>(const void* data);
 #endif
 
-void OutputBuffer::insertN(const void* __restrict data, unsigned len) __restrict
+void OutputBuffer::insertN(const void* data, unsigned len)
 {
 	byte* newEnd = end + len;
 	if (likely(newEnd <= finish)) {
@@ -76,7 +76,7 @@ byte* OutputBuffer::release(unsigned& si
 	return result;
 }
 
-void OutputBuffer::insertGrow(const void* __restrict data, unsigned len) __restrict
+void OutputBuffer::insertGrow(const void* data, unsigned len)
 {
 	byte* pos = allocateGrow(len);
 	memcpy(pos, data, len);
