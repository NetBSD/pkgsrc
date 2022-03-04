$NetBSD: patch-src_dos_dos__programs.cpp,v 1.3 2022/03/04 07:41:14 nia Exp $

dos_programs.cpp: In member function 'bool AUTOTYPE::ReadDoubleArg(const string&, const char*, const double&, const double&, const double&, double&)':
dos_programs.cpp:5556:12: error: expected unqualified-id before '(' token
   if (std::isfinite(user_value)) {

--- src/dos/dos_programs.cpp.orig	2022-03-01 02:12:39.000000000 +0000
+++ src/dos/dos_programs.cpp
@@ -6756,11 +6756,7 @@ bool AUTOTYPE::ReadDoubleArg(const std::
 	if (cmd->FindString(flag, str_value, true)) {
 		// Can the user's value be parsed?
 		const double user_value = to_finite<double>(str_value);
-#if defined(__FreeBSD__) || defined(MACOSX) || defined(EMSCRIPTEN) || ((defined(ANDROID) || defined(__ANDROID__)) && defined(__clang__))
-		if (isfinite(user_value)) { /* *sigh* Really, clang, really? */
-#else
-		if (std::isfinite(user_value)) {
-#endif
+		if (isfinite(user_value)) {
 			result = true;
 
 			// Clamp the user's value if needed
