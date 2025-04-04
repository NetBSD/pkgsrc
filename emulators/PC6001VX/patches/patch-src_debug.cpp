$NetBSD: patch-src_debug.cpp,v 1.1 2025/04/04 23:32:21 tsutsui Exp $

- workaround for upstream issue #19:
  https://github.com/eighttails/PC6001VX/issues/19
  Filenames are implicitly converted to uppercase on loadmem and
  savemem commands on debugger mode.

--- src/debug.cpp.orig	2025-04-04 18:24:39.861946787 +0000
+++ src/debug.cpp
@@ -1044,7 +1044,9 @@ void cWndMon::Shift( void )
 		argv.Str  = Argv.front();
 		
 		// 大文字化
+#if defined(_WIN32) || defined(_WIN64)
 		std::transform( argv.Str.begin(), argv.Str.end(), argv.Str.begin(), ::toupper );
+#endif
 		
 		if( argv.Str.front() == '#' ){
 			size = true;
