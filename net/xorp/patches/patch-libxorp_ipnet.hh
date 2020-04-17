$NetBSD: patch-libxorp_ipnet.hh,v 1.2 2020/04/17 00:20:45 joerg Exp $

--- libxorp/ipnet.hh.orig	2009-01-05 18:30:57.000000000 +0000
+++ libxorp/ipnet.hh
@@ -107,6 +107,10 @@ public:
 		(masked_addr() == other.masked_addr()));
     }
 
+    bool operator!=(const IPNet& other) const {
+	return !(*this == other);
+    }
+
     /**
      * Less-than comparison for subnets (see body for description).
      *
@@ -563,13 +567,13 @@ template <class A> void
 IPNet<A>::initialize_from_string(const char *cp)
     throw (InvalidString, InvalidNetmaskLength)
 {
-    char *slash = strrchr(cp, '/');
+    const char *slash = strrchr(cp, '/');
     if (slash == 0)
 	xorp_throw(InvalidString, "Missing slash");
 
     if (*(slash + 1) == 0)
 	xorp_throw(InvalidString, "Missing prefix length");
-    char *n = slash + 1;
+    const char *n = slash + 1;
     while (*n != 0) {
 	if (*n < '0' || *n > '9') {
 	    xorp_throw(InvalidString, "Bad prefix length");
