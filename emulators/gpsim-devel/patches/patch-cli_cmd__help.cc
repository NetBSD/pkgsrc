$NetBSD: patch-cli_cmd__help.cc,v 1.1 2011/12/19 15:58:40 wiz Exp $

--- cli/cmd_help.cc.orig	2005-08-31 14:46:33.000000000 +0000
+++ cli/cmd_help.cc
@@ -22,6 +22,7 @@ Boston, MA 02111-1307, USA.  */
 #include <iostream>
 #include <iomanip>
 #include <string>
+#include <string.h>
 
 #include "command.h"
 #include "cmd_help.h"
