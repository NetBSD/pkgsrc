$NetBSD: patch-src_libs_zbxsysinfo_netbsd_net.c,v 1.1 2023/03/26 11:58:58 he Exp $

Plug in parts of the code from netstat's if.c, to transform
from being a kmem groveller to using sysctl() to get interface
statistics.

--- src/libs/zbxsysinfo/netbsd/net.c.orig	2020-08-24 07:46:37.000000000 +0000
+++ src/libs/zbxsysinfo/netbsd/net.c
@@ -22,21 +22,140 @@
 #include "zbxjson.h"
 #include "log.h"
 
+#include <net/route.h>
+#include <net/if.h>
+#include <net/if_dl.h>
+#include <net/if_types.h>
+
+#if 0 /* used by old code */
 static struct nlist kernel_symbols[] =
 {
 	{"_ifnet", N_UNDF, 0, 0, 0},
 	{"_tcbtable", N_UNDF, 0, 0, 0},
 	{NULL, 0, 0, 0, 0}
 };
+#endif
+
+static void get_rtaddrs(int, struct sockaddr *, struct sockaddr **);
+
+static void
+get_rtaddrs(int addrs, struct sockaddr *sa, struct sockaddr **rti_info)
+{
+        int i;
+
+        for (i = 0; i < RTAX_MAX; i++) {
+                if (addrs & (1 << i)) {
+                        rti_info[i] = sa;
+                        sa = (struct sockaddr *)((char *)(sa) +
+                            RT_ROUNDUP(sa->sa_len));
+                } else
+                        rti_info[i] = NULL;
+        }
+}
+
 
 #define IFNET_ID 0
 
 static int	get_ifdata(const char *if_name,
-		zbx_uint64_t *ibytes, zbx_uint64_t *ipackets, zbx_uint64_t *ierrors, zbx_uint64_t *idropped,
-		zbx_uint64_t *obytes, zbx_uint64_t *opackets, zbx_uint64_t *oerrors,
-		zbx_uint64_t *tbytes, zbx_uint64_t *tpackets, zbx_uint64_t *terrors,
+		zbx_uint64_t *ibytes, zbx_uint64_t *ipackets,
+		zbx_uint64_t *ierrors, zbx_uint64_t *idropped,
+		zbx_uint64_t *obytes, zbx_uint64_t *opackets,
+		zbx_uint64_t *oerrors, zbx_uint64_t *tbytes,
+		zbx_uint64_t *tpackets, zbx_uint64_t *terrors,
 		zbx_uint64_t *icollisions, char **error)
 {
+	struct if_msghdr *ifm;
+	int mib[6] = { CTL_NET, AF_ROUTE, 0, 0, NET_RT_IFLIST, 0 };
+	static char *buf = NULL;
+	static size_t olen;
+	size_t len;
+	char *next, *lim, *cp;
+	struct rt_msghdr *rtm;
+	struct if_data *ifd = NULL;
+	struct sockaddr *sa, *rti_info[RTAX_MAX];
+	struct sockaddr_dl *sdl;
+	char name[IFNAMSIZ + 1];
+	int ifindex = 0;
+	int ret = SYSINFO_RET_FAIL;
+
+	if (sysctl(mib, 6, NULL, &len, NULL, 0) == -1)
+		return FAIL;
+	if (len > olen) {
+		free(buf);
+		if ((buf = malloc(len)) == NULL) {
+			*error = zbx_strdup(NULL, "sysctl get-length failed");
+			return FAIL;
+		}
+		olen = len;
+	}
+	if (sysctl(mib, 6, buf, &len, NULL, 0) == -1) {
+		*error = zbx_strdup(NULL, "sysctl get-if-list failed");
+		return FAIL;
+	}
+
+	lim = buf + len;
+	for (next = buf; next < lim; next += rtm->rtm_msglen) {
+		/* struct if_data_ext dext; */
+
+		rtm = (struct rt_msghdr *)next;
+		if (rtm->rtm_version != RTM_VERSION)
+			continue;
+
+		switch (rtm->rtm_type) {
+		case RTM_IFINFO:
+			ifm = (struct if_msghdr *)next;
+			ifd = &ifm->ifm_data;
+
+			sa = (struct sockaddr *)(ifm + 1);
+			get_rtaddrs(ifm->ifm_addrs, sa, rti_info);
+
+			sdl = (struct sockaddr_dl *)rti_info[RTAX_IFP];
+
+			bzero(name, sizeof(name));
+			if (sdl->sdl_nlen >= IFNAMSIZ)
+				memcpy(name, sdl->sdl_data, IFNAMSIZ - 1);
+			else if (sdl->sdl_nlen > 0)
+				memcpy(name, sdl->sdl_data, sdl->sdl_nlen);
+
+			if (if_name != NULL && strcmp(name, if_name) != 0)
+				continue;
+
+			ifindex = sdl->sdl_index;
+
+			if (ibytes)
+				*ibytes = ifd->ifi_ibytes;
+			if (ipackets)
+				*ipackets = ifd->ifi_ipackets;
+			if (ierrors)
+				*ierrors = ifd->ifi_ierrors;
+			if (idropped)
+				*idropped = ifd->ifi_iqdrops;
+			if (obytes)
+				*obytes = ifd->ifi_obytes;
+			if (opackets)
+				*opackets = ifd->ifi_opackets;
+			if (oerrors)
+				*oerrors = ifd->ifi_oerrors;
+			if (tbytes)
+				*tbytes = ifd->ifi_ibytes +
+					ifd->ifi_obytes;
+			if (tpackets)
+				*tpackets = ifd->ifi_ipackets +
+					ifd->ifi_opackets;
+			if (terrors)
+				*terrors = ifd->ifi_ierrors +
+					ifd->ifi_oerrors;
+			if (icollisions)
+				*icollisions = ifd->ifi_collisions;
+
+			ret = SYSINFO_RET_OK;
+		default:
+			continue;
+		}
+	}
+
+#if 0 /* old code uses nlist & kmem groveling */
+
 	struct ifnet_head	head;
 	struct ifnet		*ifp;
 	struct ifnet		v;
@@ -143,6 +262,7 @@ static int	get_ifdata(const char *if_nam
 		*error = zbx_strdup(NULL, "Cannot find information for this network interface.");
 		return SYSINFO_RET_FAIL;
 	}
+#endif
 
 	return ret;
 }
