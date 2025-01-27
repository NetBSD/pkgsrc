$NetBSD: patch-GetIfInfo.cc,v 1.1 2025/01/27 14:11:32 wiz Exp $

Fix
include/net-snmp/net-snmp-config.h:46:47: error: conflicting declaration of 'void netsnmp_unused_function()' with 'C' linkage

--- GetIfInfo.cc.orig	2025-01-27 14:09:50.286946451 +0000
+++ GetIfInfo.cc
@@ -23,6 +23,7 @@
 
 #include "pc.h"
 
+extern "C" {
 // UCD SNMP includes
 #include "ucd-snmp/ucd-snmp-config.h"
 #include "ucd-snmp/asn1.h"
@@ -33,6 +34,7 @@
 #include "ucd-snmp/snmp.h"
 #include "ucd-snmp/system.h"
 #include "ucd-snmp/default_store.h"
+}
 
 #include "GetIfInfo.h"
 #include "Pctest.h"
