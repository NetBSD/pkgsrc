$NetBSD: patch-lib_sys-limits.h,v 1.1 2019/12/19 09:36:33 jperkin Exp $

Avoid conflict with sys/limits.h guard.

--- lib/sys-limits.h.orig	2018-06-24 23:17:59.000000000 +0000
+++ lib/sys-limits.h
@@ -15,8 +15,8 @@
    You should have received a copy of the GNU General Public License
    along with this program; if not, see <https://www.gnu.org/licenses/>.  */
 
-#ifndef _SYS_LIMITS_H
-#define _SYS_LIMITS_H
+#ifndef _GREP_SYS_LIMITS_H
+#define _GREP_SYS_LIMITS_H
 
 #include <limits.h>
 
