$NetBSD: patch-Source_Core_Common_x64CPUDetect.cpp,v 1.1 2020/04/20 00:34:20 joerg Exp $

--- Source/Core/Common/x64CPUDetect.cpp.orig	2020-04-19 15:52:44.582835202 +0000
+++ Source/Core/Common/x64CPUDetect.cpp
@@ -42,13 +42,18 @@ static inline void __cpuid(int info[4], 
 }
 
 #define _XCR_XFEATURE_ENABLED_MASK 0
-static u64 _xgetbv(u32 index)
+static u64 my_xgetbv(u32 index)
 {
 	u32 eax, edx;
 	__asm__ __volatile__("xgetbv" : "=a"(eax), "=d"(edx) : "c"(index));
 	return ((u64)edx << 32) | eax;
 }
 
+#else
+static u64 my_xgetbv(u32 index)
+{
+	return _xgetbv(index);
+}
 #endif // ifndef _WIN32
 
 CPUInfo cpu_info;
@@ -134,7 +139,7 @@ void CPUInfo::Detect()
 		//  - XGETBV result has the XCR bit set.
 		if (((cpu_id[2] >> 28) & 1) && ((cpu_id[2] >> 27) & 1))
 		{
-			if ((_xgetbv(_XCR_XFEATURE_ENABLED_MASK) & 0x6) == 0x6)
+			if ((my_xgetbv(_XCR_XFEATURE_ENABLED_MASK) & 0x6) == 0x6)
 			{
 				bAVX = true;
 				if ((cpu_id[2] >> 12) & 1)
