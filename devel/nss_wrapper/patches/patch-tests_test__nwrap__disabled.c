$NetBSD: patch-tests_test__nwrap__disabled.c,v 1.1 2025/09/06 18:27:52 riastradh Exp $

Don't pass static getpwuid(...)->pw_name buffer back into getpwnam,
which may overwrite the same buffer as it works, causing trouble on
NetBSD:

[ RUN      ] test_nwrap_passwd_group
[  ERROR   ] --- pwd
[   LINE   ] --- /home/riastradh/pkgsrc/current/work/devel/nss_wrapper/work/nss_wrapper-1.1.16/tests/test_nwrap_disabled.c:29: error: Failure!
[  FAILED  ] test_nwrap_passwd_group

--- tests/test_nwrap_disabled.c.orig	2020-03-17 17:23:32.000000000 +0000
+++ tests/test_nwrap_disabled.c
@@ -2,6 +2,7 @@
 
 #include <stdarg.h>
 #include <stddef.h>
+#include <stdlib.h>
 #include <setjmp.h>
 #include <cmocka.h>
 
@@ -17,6 +18,7 @@
 
 static void test_nwrap_passwd_group(void **state)
 {
+	char *name;
 	struct passwd *pwd;
 	struct group *grp;
 
@@ -25,14 +27,20 @@ static void test_nwrap_passwd_group(void
 	pwd = getpwuid(getuid());
 	assert_non_null(pwd);
 
-	pwd = getpwnam(pwd->pw_name);
+	name = strdup(pwd->pw_name);
+	assert_non_null(name);
+	pwd = getpwnam(name);
 	assert_non_null(pwd);
+	free(name);
 
 	grp = getgrgid(pwd->pw_gid);
 	assert_non_null(grp);
 
+	name = strdup(grp->gr_name);
+	assert_non_null(name);
 	grp = getgrnam(grp->gr_name);
 	assert_non_null(grp);
+	free(name);
 }
 
 /* Test libnsl */
