$NetBSD: patch-inc_enc__shiftjis.hpp,v 1.1 2026/01/26 19:43:32 nia Exp $

NetBSD does not recognize SHIFT-JIS as a valid encoding without the
underscore.

--- inc/enc_shiftjis.hpp.orig	2026-01-26 19:15:04.811539545 +0000
+++ inc/enc_shiftjis.hpp
@@ -18,7 +18,11 @@ class shiftjis_validator : public jis_validator (priva
 class shiftjis_validator : public jis_validator
 {
 private:
+#ifdef __NetBSD__
+	constexpr static char const * m_iconvcode = "SHIFT_JIS";
+#else
 	constexpr static char const * m_iconvcode = "SHIFT-JIS";
+#endif
 
 public:
 	shiftjis_validator() :
@@ -29,4 +33,4 @@ class shiftjis_validator : public jis_validator (priva
 };
 
 } // namespace motoi
-#endif
\ No newline at end of file
+#endif
