$NetBSD: patch-src_util.c,v 1.1 2018/06/26 09:54:30 jperkin Exp $

Provide getgrouplist for SunOS.  This is available in newer releases,
so if that becomes a problem we'll need to add a configure test.

--- src/util.c.orig	2013-10-15 20:25:19.000000000 +0000
+++ src/util.c
@@ -259,6 +259,46 @@ spawn_with_login_uid (GDBusMethodInvocat
         return ret;
 }
 
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
 gint
 get_user_groups (const gchar  *user,
                  gid_t         group,
