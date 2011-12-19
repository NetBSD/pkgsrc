$NetBSD: patch-gui_settings__exdbm.cc,v 1.1 2011/12/19 15:52:21 wiz Exp $

Add missing include.

--- gui/settings_exdbm.cc.orig	2004-07-06 05:20:20.000000000 +0000
+++ gui/settings_exdbm.cc
@@ -19,6 +19,7 @@ along with gpsim; see the file COPYING. 
 the Free Software Foundation, 59 Temple Place - Suite 330,
 Boston, MA 02111-1307, USA.  */
 
+#include <stdlib.h>
 #include "settings_exdbm.h"
 
 
