$NetBSD: patch-gnu_sys-limits.h,v 1.1 2019/05/02 20:27:43 wiedi Exp $

Don't conflict with sys/limits.h on SunOS

--- gnu/sys-limits.h.orig	2019-01-02 18:16:01.000000000 +0000
+++ gnu/sys-limits.h
@@ -15,8 +15,8 @@
    You should have received a copy of the GNU General Public License
    along with this program; if not, see <https://www.gnu.org/licenses/>.  */
 
-#ifndef _SYS_LIMITS_H
-#define _SYS_LIMITS_H
+#ifndef _SYS__LIMITS_H
+#define _SYS__LIMITS_H
 
 #include <limits.h>
 
