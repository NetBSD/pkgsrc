$NetBSD: patch-src_dos_dos__programs.cpp,v 1.2 2021/08/10 11:03:50 nia Exp $

dos_programs.cpp: In member function 'bool AUTOTYPE::ReadDoubleArg(const string&, const char*, const double&, const double&, const double&, double&)':
dos_programs.cpp:5556:12: error: expected unqualified-id before '(' token
   if (std::isfinite(user_value)) {

--- src/dos/dos_programs.cpp.orig	2021-08-01 07:45:55.000000000 +0000
+++ src/dos/dos_programs.cpp
@@ -6446,11 +6446,7 @@ bool AUTOTYPE::ReadDoubleArg(const std::
 	if (cmd->FindString(flag, str_value, true)) {
 		// Can the user's value be parsed?
 		const double user_value = to_finite<double>(str_value);
-#if defined(MACOSX) || defined(EMSCRIPTEN) || ((defined(ANDROID) || defined(__ANDROID__)) && defined(__clang__))
 		if (isfinite(user_value)) { /* *sigh* Really, clang, really? */
-#else
-		if (std::isfinite(user_value)) {
-#endif
 			result = true;
 
 			// Clamp the user's value if needed
