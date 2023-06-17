$NetBSD: patch-src_misc.cc,v 1.2 2023/06/17 16:50:53 wiz Exp $

../src/misc.cc: In function 'gint date_get_first_day_of_week()':
../src/misc.cc:262:29: error: 'LC_ALL' was not declared in this scope; did you mean 'P_ALL'?
  262 |  current_locale = setlocale(LC_ALL, NULL);
      |                             ^~~~~~
      |                             P_ALL
../src/misc.cc:262:19: error: 'setlocale' was not declared in this scope; did you mean '_locale'?
  262 |  current_locale = setlocale(LC_ALL, NULL);
      |                   ^~~~~~~~~
      |                   _locale
https://github.com/BestImageViewer/geeqie/pull/1110

--- src/misc.cc.orig	2023-06-17 12:12:30.000000000 +0000
+++ src/misc.cc
@@ -18,6 +18,8 @@
  * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
  */
 
+#include <locale.h>
+
 #include "main.h"
 #include "misc.h"
 
