$NetBSD: patch-include_libfyaml_libfyaml-vlsize.h,v 1.1 2026/04/01 08:53:14 tnn Exp $

https://github.com/pantoniou/libfyaml/commit/0982fcefc6a16d4c8cb5b06747d3fc8e630de3ae.patch
https://github.com/pantoniou/libfyaml/commit/9192deaac095f9881cc1e5756dede683f36b09d6.patch

--- include/libfyaml/libfyaml-vlsize.h.orig	2026-03-15 13:48:50.000000000 +0000
+++ include/libfyaml/libfyaml-vlsize.h
@@ -810,13 +810,18 @@ fy_decode_size(const uint8_t *start, siz
 static inline const uint8_t *
 fy_decode_size_nocheck(const uint8_t *start, size_t *sizep)
 {
-	return fy_decode_size32_nocheck(start, sizep);
+	uint64_t sz;
+	const uint8_t *ret;
+
+	ret = fy_decode_size32_nocheck(start, &sz);
+	*sizep = (size_t)sz;
+	return ret;
 }
 
 static inline const uint8_t *
 fy_skip_size(const uint8_t *start, size_t bufsz)
 {
-	return fy_skip_size32(start, bufsz, &sz);
+	return fy_skip_size32(start, bufsz);
 }
 
 static inline const uint8_t *
