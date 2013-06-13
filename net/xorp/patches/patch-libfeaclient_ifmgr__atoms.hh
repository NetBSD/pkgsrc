$NetBSD: patch-libfeaclient_ifmgr__atoms.hh,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- libfeaclient/ifmgr_atoms.hh.orig	2013-06-13 18:53:54.000000000 +0000
+++ libfeaclient/ifmgr_atoms.hh
@@ -52,7 +52,7 @@ class IfMgrIPv6Atom;
  */
 class IfMgrIfTree {
 public:
-    typedef map<const string, IfMgrIfAtom> IfMap;
+    typedef map<string, IfMgrIfAtom> IfMap;
 
 public:
 
@@ -268,7 +268,7 @@ protected:
  */
 class IfMgrIfAtom {
 public:
-    typedef map<const string, IfMgrVifAtom> VifMap;
+    typedef map<string, IfMgrVifAtom> VifMap;
 
 public:
     IfMgrIfAtom(const string& name);
@@ -336,8 +336,8 @@ protected:
  */
 class IfMgrVifAtom {
 public:
-    typedef map<const IPv4, IfMgrIPv4Atom> IPv4Map;
-    typedef map<const IPv6, IfMgrIPv6Atom> IPv6Map;
+    typedef map<IPv4, IfMgrIPv4Atom> IPv4Map;
+    typedef map<IPv6, IfMgrIPv6Atom> IPv6Map;
 
 public:
     IfMgrVifAtom(const string& name);
