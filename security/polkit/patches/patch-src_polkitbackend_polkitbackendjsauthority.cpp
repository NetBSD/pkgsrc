$NetBSD: patch-src_polkitbackend_polkitbackendjsauthority.cpp,v 1.1 2018/05/14 09:30:35 jperkin Exp $

Provide getgrouplist for SunOS.  This is available in newer Solaris,
so if that becomes a problem we'll need to add a configure test.

--- src/polkitbackend/polkitbackendjsauthority.cpp.orig	2018-04-03 18:16:49.000000000 +0000
+++ src/polkitbackend/polkitbackendjsauthority.cpp
@@ -55,6 +55,46 @@
 #error "This code is not safe in SpiderMonkey exact stack rooting configurations"
 #endif
 
+#ifdef __sun
+int
+getgrouplist(const char *uname, gid_t agroup, gid_t *groups, int *grpcnt)
+{
+	const struct group *grp;
+	int i, maxgroups, ngroups, ret;
+
+	ret = 0;
+	ngroups = 0;
+	maxgroups = *grpcnt;
+	groups ? groups[ngroups++] = agroup : ngroups++;
+	if (maxgroups > 1)
+		groups ? groups[ngroups++] = agroup : ngroups++;
+	setgrent();
+	while ((grp = getgrent()) != NULL) {
+		if (groups) {
+			for (i = 0; i < ngroups; i++) {
+				if (grp->gr_gid == groups[i])
+					goto skip;
+			}
+		}
+		for (i = 0; grp->gr_mem[i]; i++) {
+			if (!strcmp(grp->gr_mem[i], uname)) {
+				if (ngroups >= maxgroups) {
+					ret = -1;
+					break;
+				}
+				groups ? groups[ngroups++] = grp->gr_gid : ngroups++;
+				break;
+			}
+		}
+skip:
+		;
+	}
+	endgrent();
+	*grpcnt = ngroups;
+	return (ret);
+}
+#endif
+
 /**
  * SECTION:polkitbackendjsauthority
  * @title: PolkitBackendJsAuthority
