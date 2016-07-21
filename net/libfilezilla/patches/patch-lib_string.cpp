$NetBSD: patch-lib_string.cpp,v 1.4 2016/07/21 17:16:17 wiz Exp $

SVN 7668

--- lib/string.cpp.orig	2016-06-20 08:08:07.000000000 +0000
+++ lib/string.cpp
@@ -95,6 +95,59 @@ std::wstring to_wstring(std::string cons
 // Depending which one is used, declare iconv_second_arg_type as either char* or char const*
 extern "C" typedef size_t (*iconv_prototype_with_const)(iconv_t, char const**, size_t *, char**, size_t *);
 typedef std::conditional<std::is_same<decltype(&iconv), iconv_prototype_with_const>::value, char const*, char*>::type iconv_second_arg_type;
+
+namespace {
+// On some platforms, e.g. those derived from SunOS, iconv does not understand "WCHAR_T", so we
+// need to guess an encoding.
+char const* const calc_wchar_t_encoding()
+{
+	auto try_encoding = [](char const* const encoding) -> bool {
+		iconv_t cd = iconv_open(encoding, "UTF-8");
+		if (cd == reinterpret_cast<iconv_t>(-1)) {
+			return false;
+		}
+		iconv_close(cd);
+		return true;
+		
+	};
+	if (try_encoding("WCHAR_T")) {
+		return "WCHAR_T";
+	}
+	else {
+		// Explicitly specify endianess, otherwise we'll get a BOM prefixed to everything
+
+		int const i = 1;
+		char const* p = reinterpret_cast<char const*>(&i);
+		bool little_endian = p[0] == 1;
+
+		if (sizeof(wchar_t) == 4) {
+			if (little_endian && try_encoding("UTF-32LE")) {
+				return "UTF-32LE";
+			}
+			if (!little_endian && try_encoding("UTF-32BE")) {
+				return "UTF-32BE";
+			}
+		}
+		else if (sizeof(wchar_t) == 2) {
+			if (little_endian && try_encoding("UTF-16LE")) {
+				return "UTF-16LE";
+			}
+			if (!little_endian && try_encoding("UTF-16BE")) {
+				return "UTF-16BE";
+			}
+		}
+	}
+
+	// Oh dear...
+	return "WCHAR_T";
+}
+
+char const* wchar_t_encoding()
+{
+	static char const* const encoding = calc_wchar_t_encoding();
+	return encoding;
+}
+}
 #endif
 
 std::wstring to_wstring_from_utf8(std::string const& in)
@@ -111,7 +164,7 @@ std::wstring to_wstring_from_utf8(std::s
 			MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, in_p, len, out_p, len);
 		}
 #else
-		iconv_t cd = iconv_open("WCHAR_T", "UTF-8");
+		iconv_t cd = iconv_open(wchar_t_encoding(), "UTF-8");
 		if (cd != reinterpret_cast<iconv_t>(-1)) {
 			auto in_p = const_cast<iconv_second_arg_type>(in.c_str());
 			size_t in_len = in.size();
@@ -175,7 +228,7 @@ std::string FZ_PUBLIC_SYMBOL to_utf8(std
 			WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, in_p, len, out_p, len, 0, 0);
 		}
 #else
-		iconv_t cd = iconv_open("UTF-8", "WCHAR_T");
+		iconv_t cd = iconv_open("UTF-8", wchar_t_encoding());
 		if (cd != reinterpret_cast<iconv_t>(-1)) {
 			auto in_p = reinterpret_cast<iconv_second_arg_type>(const_cast<wchar_t*>(in.c_str()));
 			size_t in_len = in.size() * sizeof(wchar_t);
