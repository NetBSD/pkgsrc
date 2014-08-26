$NetBSD: patch-openmpt123_openmpt123.hpp,v 1.1 2014/08/26 10:44:15 wiz Exp $

NetBSD defines both TIOCGSIZE and TIOCGWINSZ, but struct ttysize does not
contain the referenced members.

http://bugs.openmpt.org/view.php?id=580

--- openmpt123/openmpt123.hpp.orig	2014-02-01 16:52:29.000000000 +0000
+++ openmpt123/openmpt123.hpp
@@ -336,18 +336,18 @@ struct commandlineflags {
 					terminal_height = tmp;
 				}
 			}
-			#if defined(TIOCGSIZE)
-				struct ttysize ts;
-				if ( ioctl( STDERR_FILENO, TIOCGSIZE, &ts ) >= 0 ) {
-					terminal_width = ts.ts_cols;
-					terminal_height = ts.ts_rows;
-				}
-			#elif defined(TIOCGWINSZ)
+			#if defined(TIOCGWINSZ)
 				struct winsize ts;
 				if ( ioctl( STDERR_FILENO, TIOCGWINSZ, &ts ) >= 0 ) {
 					terminal_width = ts.ws_col;
 					terminal_height = ts.ws_row;
 				}
+			#elif defined(TIOCGSIZE)
+				struct ttysize ts;
+				if ( ioctl( STDERR_FILENO, TIOCGSIZE, &ts ) >= 0 ) {
+					terminal_width = ts.ts_cols;
+					terminal_height = ts.ts_rows;
+				}
 			#endif
 		}
 #endif
