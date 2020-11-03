$NetBSD: patch-src_libs_zbxsysinfo_netbsd_net.c,v 1.1 2020/11/03 22:46:23 otis Exp $

Rework interface statistics code from using kvm to using sysctl interface.

--- src/libs/zbxsysinfo/netbsd/net.c.orig	2020-08-24 09:42:55.000000000 +0000
+++ src/libs/zbxsysinfo/netbsd/net.c
@@ -22,6 +22,9 @@
 #include "zbxjson.h"
 #include "log.h"
 
+#include <net/route.h>
+#include <net/if_dl.h>
+
 static struct nlist kernel_symbols[] =
 {
 	{"_ifnet", N_UNDF, 0, 0, 0},
@@ -31,43 +34,91 @@ static struct nlist kernel_symbols[] =
 
 #define IFNET_ID 0
 
+static void
+get_rtaddrs(int addrs, struct sockaddr *sa, struct sockaddr **rti_info)
+{
+    int i;
+
+    for (i = 0; i < RTAX_MAX; i++) {
+        if (addrs & (1 << i)) {
+            rti_info[i] = sa;
+            sa = (struct sockaddr *)((char *)(sa) +
+                RT_ROUNDUP(sa->sa_len));
+        } else
+            rti_info[i] = NULL;
+    }
+}
+
+
 static int	get_ifdata(const char *if_name,
 		zbx_uint64_t *ibytes, zbx_uint64_t *ipackets, zbx_uint64_t *ierrors, zbx_uint64_t *idropped,
 		zbx_uint64_t *obytes, zbx_uint64_t *opackets, zbx_uint64_t *oerrors,
 		zbx_uint64_t *tbytes, zbx_uint64_t *tpackets, zbx_uint64_t *terrors,
 		zbx_uint64_t *icollisions, char **error)
 {
-	struct ifnet_head	head;
-	struct ifnet		*ifp;
-	struct ifnet		v;
-
-	kvm_t	*kp;
-	int	len = 0;
-	int	ret = SYSINFO_RET_FAIL;
+	struct	if_msghdr *ifm;
+	int		mib[6] = { CTL_NET, AF_ROUTE, 0, 0, NET_RT_IFLIST, 0 };
+	char	*buf = NULL;
+	char	*lim, *next;
+	struct	rt_msghdr *rtm;
+	struct	if_data *ifd = NULL;
+	struct	sockaddr *sa, *rti_info[RTAX_MAX];
+	struct	sockaddr_dl *sdl;
+
+	size_t	len = 0;
+	size_t	olen = 0;
+	int		ret = SYSINFO_RET_FAIL;
+
+	static char name[IFNAMSIZ];
 
 	if (NULL == if_name || '\0' == *if_name)
 	{
 		*error = zbx_strdup(NULL, "Network interface name cannot be empty.");
-		return FAIL;
+		ret = FAIL;
+		goto out;
 	}
 
-	if (NULL == (kp = kvm_open(NULL, NULL, NULL, O_RDONLY, NULL))) /* requires root privileges */
-	{
-		*error = zbx_strdup(NULL, "Cannot obtain a descriptor to access kernel virtual memory.");
-		return FAIL;
-	}
-
-	if (N_UNDF == kernel_symbols[IFNET_ID].n_type)
-		if (0 != kvm_nlist(kp, &kernel_symbols[0]))
-			kernel_symbols[IFNET_ID].n_type = N_UNDF;
-
-	if (N_UNDF != kernel_symbols[IFNET_ID].n_type)
-	{
-		len = sizeof(struct ifnet_head);
-
-		if (kvm_read(kp, kernel_symbols[IFNET_ID].n_value, &head, len) >= len)
-		{
-			len = sizeof(struct ifnet);
+    if (sysctl(mib, 6, NULL, &len, NULL, 0) == -1) {
+        *error = zbx_strdup(NULL, "Failed to read network interfaces data");
+		ret = FAIL;
+		goto out;
+	}
+
+    if (len > olen) {
+        free(buf);
+        if ((buf = zbx_malloc(NULL, len)) == NULL) {
+			*error = zbx_strdup(NULL, "Failed to allocate buffer for network interfaces data");
+			ret = FAIL;
+			goto out;
+		}
+        olen = len;
+    }
+    if (sysctl(mib, 6, buf, &len, NULL, 0) == -1) {
+		*error = zbx_strdup(NULL, "Failed to allocate buffer for network interfaces data");
+		ret = FAIL;
+		goto out;
+	}
+
+	lim = buf + len;
+    for (next = buf; next < lim; next += rtm->rtm_msglen) {
+        rtm = (struct rt_msghdr *)next;
+        if ((rtm->rtm_version == RTM_VERSION) &&
+                (rtm->rtm_type == RTM_IFINFO)) {
+            ifm = (struct if_msghdr *)next;
+            ifd = &ifm->ifm_data;
+
+            sa = (struct sockaddr *)(ifm + 1);
+            get_rtaddrs(ifm->ifm_addrs, sa, rti_info);
+
+            sdl = (struct sockaddr_dl *)rti_info[RTAX_IFP];
+            if (sdl == NULL || sdl->sdl_family != AF_LINK) {
+                continue;
+            }
+            bzero(name, sizeof(name));
+            if (sdl->sdl_nlen >= IFNAMSIZ)
+                memcpy(name, sdl->sdl_data, IFNAMSIZ - 1);
+            else if (sdl->sdl_nlen > 0)
+                memcpy(name, sdl->sdl_data, sdl->sdl_nlen);
 
 			/* if_ibytes;		total number of octets received */
 			/* if_ipackets;		packets received on interface */
@@ -101,42 +152,38 @@ static int	get_ifdata(const char *if_nam
 			if (icollisions)
 				*icollisions = 0;
 
-			for (ifp = head.tqh_first; ifp; ifp = v.if_list.tqe_next)
+			if (0 == strcmp(if_name, name))
 			{
-				if (kvm_read(kp, (u_long)ifp, &v, len) < len)
-					break;
-
-				if (0 == strcmp(if_name, v.if_xname))
-				{
-					if (ibytes)
-						*ibytes += v.if_ibytes;
-					if (ipackets)
-						*ipackets += v.if_ipackets;
-					if (ierrors)
-						*ierrors += v.if_ierrors;
-					if (idropped)
-						*idropped += v.if_iqdrops;
-					if (obytes)
-						*obytes += v.if_obytes;
-					if (opackets)
-						*opackets += v.if_opackets;
-					if (oerrors)
-						*oerrors += v.if_oerrors;
-					if (tbytes)
-						*tbytes += v.if_ibytes + v.if_obytes;
-					if (tpackets)
-						*tpackets += v.if_ipackets + v.if_opackets;
-					if (terrors)
-						*terrors += v.if_ierrors + v.if_oerrors;
-					if (icollisions)
-						*icollisions += v.if_collisions;
-					ret = SYSINFO_RET_OK;
-				}
+				if (ibytes)
+					*ibytes += ifd->ifi_ibytes;
+				if (ipackets)
+					*ipackets += ifd->ifi_ipackets;
+				if (ierrors)
+					*ierrors += ifd->ifi_ierrors;
+				if (idropped)
+					*idropped += ifd->ifi_iqdrops;
+				if (obytes)
+					*obytes += ifd->ifi_obytes;
+				if (opackets)
+					*opackets += ifd->ifi_opackets;
+				if (oerrors)
+					*oerrors += ifd->ifi_oerrors;
+				if (tbytes)
+					*tbytes += ifd->ifi_ibytes + ifd->ifi_obytes;
+				if (tpackets)
+					*tpackets += ifd->ifi_ipackets + ifd->ifi_opackets;
+				if (terrors)
+					*terrors += ifd->ifi_ierrors + ifd->ifi_oerrors;
+				if (icollisions)
+					*icollisions += ifd->ifi_collisions;
+				ret = SYSINFO_RET_OK;
+				goto out;
 			}
 		}
 	}
 
-	kvm_close(kp);
+out:
+	free(buf);
 
 	if (SYSINFO_RET_FAIL == ret)
 	{
