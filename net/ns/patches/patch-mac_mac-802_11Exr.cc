$NetBSD: patch-mac_mac-802_11Exr.cc,v 1.1 2012/03/10 22:05:04 markd Exp $

Fix build with gcc4.6

--- mac/mac-802_11Ext.cc.orig	2008-04-01 02:00:23.000000000 +0000
+++ mac/mac-802_11Ext.cc
@@ -55,6 +55,7 @@
  * http://dsn.tm.uni-karlsruhe.de/english/Overhaul_NS-2.php
  */
 
+#include <stddef.h>
 #include "delay.h"
 #include "connector.h"
 #include "packet.h"
