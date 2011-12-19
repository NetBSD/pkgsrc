$NetBSD: patch-cli_socket.cc,v 1.1 2011/12/19 15:52:20 wiz Exp $

Add missing include.

--- cli/socket.cc.orig	2005-02-02 01:59:04.000000000 +0000
+++ cli/socket.cc
@@ -27,6 +27,7 @@ Boston, MA 02111-1307, USA.  */
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 #include <sys/types.h>
