$NetBSD: patch-lib_string.in.h,v 1.1 2014/06/29 06:53:23 obache Exp $

* fixes for nested include of string.h.

--- lib/string.in.h.orig	2013-12-04 15:02:02.000000000 +0000
+++ lib/string.in.h
@@ -15,6 +15,10 @@
    You should have received a copy of the GNU General Public License
    along with this program; if not, see <http://www.gnu.org/licenses/>.  */
 
+#ifdef GL_ALREADY_INCLUDE_STRING_H
+#@INCLUDE_NEXT@ @NEXT_STRING_H@
+#else
+
 #ifndef _@GUARD_PREFIX@_STRING_H
 
 #if __GNUC__ >= 3
@@ -22,8 +26,10 @@
 #endif
 @PRAGMA_COLUMNS@
 
+#define GL_ALREADY_INCLUDE_STRING_H
 /* The include_next requires a split double-inclusion guard.  */
 #@INCLUDE_NEXT@ @NEXT_STRING_H@
+#undef GL_ALREADY_INCLUDE_STRING_H
 
 #ifndef _@GUARD_PREFIX@_STRING_H
 #define _@GUARD_PREFIX@_STRING_H
@@ -1027,3 +1033,4 @@ _GL_WARN_ON_USE (strverscmp, "strverscmp
 
 #endif /* _@GUARD_PREFIX@_STRING_H */
 #endif /* _@GUARD_PREFIX@_STRING_H */
+#endif
