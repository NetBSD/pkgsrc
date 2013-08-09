$NetBSD: patch-src_in_sysctl.c,v 1.1 2013/08/09 18:15:18 riastradh Exp $

Null-terminate interface names, in case the first octet of the
link-layer address is not zero (as many MAC addresses used to have).

--- src/in_sysctl.c.orig	2004-10-31 14:33:19.000000000 +0000
+++ src/in_sysctl.c
@@ -67,6 +67,7 @@ sysctl_read(void)
 	for (next = buf; next < lim; ) {
 		struct if_msghdr *ifm, *nextifm;
 		struct sockaddr_dl *sdl;
+		char *name;
 		intf_t *i;
 
 		ifm = (struct if_msghdr *) next;
@@ -93,7 +94,11 @@ sysctl_read(void)
 		if (c_debug)
 			fprintf(stderr, "Processing %s\n", sdl->sdl_data);
 
-		i = lookup_intf(get_local_node(), sdl->sdl_data, 0, 0);
+		name = xcalloc(1, sdl->sdl_nlen + 1);
+		(void)memcpy(name, sdl->sdl_data, sdl->sdl_nlen);
+		name[sdl->sdl_nlen] = 0;
+		i = lookup_intf(get_local_node(), name, 0, 0);
+		xfree(name);
 
 		if (NULL == i)
 			continue;
