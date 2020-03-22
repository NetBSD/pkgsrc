$NetBSD: patch-curses-cursesscreen.C,v 1.2 2020/03/22 21:24:56 joerg Exp $

Fix C++ type error.

--- curses/cursesscreen.C.orig	2011-08-22 11:36:27.000000000 +0000
+++ curses/cursesscreen.C
@@ -28,6 +28,10 @@
 #include "cursesscreen.H"
 #include "cursesfield.H"
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#endif
+
 static unsigned char termStopKey= 'Z' & 31;
 
 static RETSIGTYPE bye(int dummy)
@@ -73,7 +77,12 @@ void CursesScreen::KeyReader::operator<<
 	while (input_buf.size() > 0)
 	{
 
-		char *inbuf=&input_buf[0], *outbuf=&winput_buf[winput_cnt];
+#if defined(__NetBSD__) && (__NetBSD_Version__-0 < 999001700)
+		const char *inbuf=&input_buf[0];
+#else
+		char *inbuf=&input_buf[0];
+#endif
+		char *outbuf=&winput_buf[winput_cnt];
 		size_t inbytesleft=input_buf.size(),
 			outbytesleft=winput_buf.size()-winput_cnt;
 
