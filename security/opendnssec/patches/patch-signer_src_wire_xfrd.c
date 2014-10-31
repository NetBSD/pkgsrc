$NetBSD: patch-signer_src_wire_xfrd.c,v 1.1 2014/10/31 16:32:39 he Exp $

There's no need for htonl() on values restored from a local file.
This causes IXFRs to fail, because the wrong SOA version number
is being stuffed into the IXFR requests(!)

--- signer/src/wire/xfrd.c.orig	2014-07-21 09:30:09.000000000 +0000
+++ signer/src/wire/xfrd.c
@@ -265,12 +265,12 @@ xfrd_recover(xfrd_type* xfrd)
                 xfrd->timeout.tv_sec = timeout;
                 xfrd->timeout.tv_nsec = 0;
                 xfrd->master = NULL; /* acl_find_num(...) */
-                xfrd->soa.ttl = htonl(soa_ttl);
-                xfrd->soa.serial = htonl(soa_serial);
-                xfrd->soa.refresh = htonl(soa_refresh);
-                xfrd->soa.retry = htonl(soa_retry);
-                xfrd->soa.expire = htonl(soa_expire);
-                xfrd->soa.minimum = htonl(soa_minimum);
+                xfrd->soa.ttl = soa_ttl;
+                xfrd->soa.serial = soa_serial;
+                xfrd->soa.refresh = soa_refresh;
+                xfrd->soa.retry = soa_retry;
+                xfrd->soa.expire = soa_expire;
+                xfrd->soa.minimum = soa_minimum;
                 xfrd->soa.mname[0] = xfrd_recover_dname(xfrd->soa.mname+1,
                     soa_mname);
                 xfrd->soa.rname[0] = xfrd_recover_dname(xfrd->soa.rname+1,
