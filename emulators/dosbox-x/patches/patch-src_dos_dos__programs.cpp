$NetBSD: patch-src_dos_dos__programs.cpp,v 1.1 2020/07/07 12:05:49 nia Exp $

dos_programs.cpp: In member function 'bool AUTOTYPE::ReadDoubleArg(const string&, const char*, const double&, const double&, const double&, double&)':
dos_programs.cpp:5556:12: error: expected unqualified-id before '(' token
   if (std::isfinite(user_value)) {

--- src/dos/dos_programs.cpp.orig	2020-06-30 23:09:17.000000000 +0000
+++ src/dos/dos_programs.cpp
@@ -5550,11 +5550,7 @@ bool AUTOTYPE::ReadDoubleArg(const std::
 	if (cmd->FindString(flag, str_value, true)) {
 		// Can the user's value be parsed?
 		const double user_value = to_finite<double>(str_value);
-#if defined(MACOSX)
 		if (isfinite(user_value)) { /* *sigh* Really, clang, really? */
-#else
-		if (std::isfinite(user_value)) {
-#endif
 			result = true;
 
 			// Clamp the user's value if needed
