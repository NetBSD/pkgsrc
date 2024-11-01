$NetBSD: patch-dlls_nsiproxy.sys_ndis.c,v 1.1 2024/11/01 14:10:47 triaxx Exp $

NetBSD defines sdl_type as sdl_addr.dl_type in net/if_dl.h.

--- dlls/nsiproxy.sys/ndis.c.orig	2024-01-16 20:55:47.000000000 +0000
+++ dlls/nsiproxy.sys/ndis.c
@@ -207,7 +207,7 @@ static NTSTATUS if_get_physical( const c
     int mib[] = { CTL_NET, AF_ROUTE, 0, AF_LINK, NET_RT_IFLIST, 0 }, i;
     static const struct type_lookup
     {
-        u_char sdl_type;
+        u_char sa_dl_type;
         IFTYPE mib_type;
     } types[] =
     {
@@ -246,7 +246,7 @@ static NTSTATUS if_get_physical( const c
             continue;
 
         for (i = 0; i < ARRAY_SIZE(types); i++)
-            if (sdl->sdl_type == types[i].sdl_type)
+            if (sdl->sdl_type == types[i].sa_dl_type)
             {
                 *type = types[i].mib_type;
                 break;
