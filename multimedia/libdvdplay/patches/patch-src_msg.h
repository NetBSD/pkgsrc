$NetBSD: patch-src_msg.h,v 1.1 2025/10/12 02:57:35 mrg Exp $

Include dvdplay.h and fix the prototype to match functions.

--- src/msg.h.orig	2025-10-11 19:47:27.261813594 -0700
+++ src/msg.h	2025-10-11 19:37:26.539660978 -0700
@@ -21,7 +21,9 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
  *****************************************************************************/
 
-void _dvdplay_Err  ( const dvdplay_ptr, const char * psz_format, ... );
-void _dvdplay_Warn ( const dvdplay_ptr, const char * psz_format, ... );
-void _dvdplay_Dbg  ( const dvdplay_ptr, const char * psz_format, ... );
-void _dvdplay_Trace( const dvdplay_ptr, const char * psz_format, ... );
+#include "dvdplay/dvdplay.h"
+
+void _dvdplay_err  ( const dvdplay_ptr, const char * psz_format, ... );
+void _dvdplay_warn ( const dvdplay_ptr, const char * psz_format, ... );
+void _dvdplay_dbg  ( const dvdplay_ptr, const char * psz_format, ... );
+void _dvdplay_trace( const dvdplay_ptr, const char * psz_format, ... );
