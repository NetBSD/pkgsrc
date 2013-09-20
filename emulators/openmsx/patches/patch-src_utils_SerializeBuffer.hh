$NetBSD: patch-src_utils_SerializeBuffer.hh,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/utils/SerializeBuffer.hh.orig	2013-09-20 13:17:27.000000000 +0000
+++ src/utils/SerializeBuffer.hh
@@ -37,7 +37,7 @@ public:
 	/** Insert data at the end of this buffer.
 	  * This will automatically grow this buffer.
 	  */
-	void insert(const void* __restrict data, unsigned len) __restrict
+	void insert(const void* data, unsigned len)
 	{
 #ifdef __GNUC__
 		if (__builtin_constant_p(len)) {
@@ -55,15 +55,15 @@ public:
 		insertN(data, len);
 	}
 #ifdef __GNUC__
-	template<unsigned N> void insertN(const void* __restrict data);
+	template<unsigned N> void insertN(const void* data);
 #endif
-	void insertN(const void* __restrict data, unsigned len);
+	void insertN(const void* data, unsigned len);
 
 	/** Insert data at a given position. This will overwrite the old data.
 	  * It's not possible to grow the buffer via this method (so the buffer
 	  * must already be big enough to hold the new data).
 	  */
-	void insertAt(unsigned pos, const void* __restrict data, unsigned len) __restrict
+	void insertAt(unsigned pos, const void* data, unsigned len)
 	{
 		assert(begin + pos + len <= finish);
 		memcpy(begin + pos, data, len);
@@ -105,7 +105,7 @@ public:
 	byte* release(unsigned& size);
 
 private:
-	void insertGrow(const void* __restrict data, unsigned len);
+	void insertGrow(const void* data, unsigned len);
 	byte* allocateGrow(unsigned len);
 
 	byte* begin;   // begin of allocated memory
