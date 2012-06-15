$NetBSD: patch-src_list.h,v 1.1 2012/06/15 18:56:09 joerg Exp $

Kill broken inline use.

--- src/list.h.orig	2012-06-15 18:10:58.000000000 +0000
+++ src/list.h
@@ -19,7 +19,6 @@ You should have received a copy of the G
 along with GNU CC; see the file COPYING.  If not, write to
 the Free Software Foundation, 59 Temple Place - Suite 330,
 Boston, MA 02111-1307, USA.  */
-
 /* As a special exception, if you link this library with files compiled with
    GCC to produce an executable, this does not cause the resulting executable
    to be covered by the GNU General Public License. This exception does not
@@ -29,11 +28,7 @@ Boston, MA 02111-1307, USA.  */
 #ifndef __LIST_H_
 #define __LIST_H_
 
-#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
-# define INLINE inline
-#else
-# define INLINE
-#endif
+#define INLINE
 
 typedef struct LinkedList {
   void *head;
