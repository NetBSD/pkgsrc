$NetBSD: patch-cli_cmd__x.cc,v 1.1 2011/12/19 15:58:40 wiz Exp $

--- cli/cmd_x.cc.orig	2005-08-31 14:46:34.000000000 +0000
+++ cli/cmd_x.cc
@@ -22,6 +22,7 @@ Boston, MA 02111-1307, USA.  */
 #include <iostream>
 #include <iomanip>
 #include <string>
+#include <typeinfo>
 
 
 #include "command.h"
