$NetBSD: patch-dns.c,v 1.1 2025/06/30 20:39:58 schmonz Exp $

Avoid shadowing system resolver's getshort(). Fixes macOS build.

--- dns.c.orig	2025-06-30 20:27:36.398753160 +0000
+++ dns.c
@@ -19,7 +19,7 @@ extern int res_search();
 #include "dns.h"
 #include "case.h"
 
-static unsigned short getshort(c) unsigned char *c;
+static unsigned short nqgetshort(c) unsigned char *c;
 { unsigned short u; u = c[0]; return (u << 8) + c[1]; }
 
 static struct { unsigned char *buf; } response;
@@ -106,8 +106,8 @@ int wanttype;
  i = responseend - responsepos;
  if (i < 4 + 3 * 2) return DNS_SOFT;
    
- rrtype = getshort(responsepos);
- rrdlen = getshort(responsepos + 8);
+ rrtype = nqgetshort(responsepos);
+ rrdlen = nqgetshort(responsepos + 8);
  responsepos += 10;
 
  if (rrtype == wanttype)
@@ -140,8 +140,8 @@ int wanttype;
  i = responseend - responsepos;
  if (i < 4 + 3 * 2) return DNS_SOFT;
    
- rrtype = getshort(responsepos);
- rrdlen = getshort(responsepos + 8);
+ rrtype = nqgetshort(responsepos);
+ rrdlen = nqgetshort(responsepos + 8);
  responsepos += 10;
 
  if (rrtype == wanttype)
@@ -178,8 +178,8 @@ int wanttype;
  i = responseend - responsepos;
  if (i < 4 + 3 * 2) return DNS_SOFT;
    
- rrtype = getshort(responsepos);
- rrdlen = getshort(responsepos + 8);
+ rrtype = nqgetshort(responsepos);
+ rrdlen = nqgetshort(responsepos + 8);
  responsepos += 10;
 
  if (rrtype == wanttype)
