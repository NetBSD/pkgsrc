$NetBSD: patch-vpdopt.c,v 1.1 2022/11/28 04:26:08 mrg Exp $

* Use /dev/smbios instead of /dev/mem on NetBSD if available.

--- vpdopt.c.orig	2022-06-27 08:06:32.000000000 -0700
+++ vpdopt.c	2022-11-27 14:28:45.657210082 -0800
@@ -147,11 +147,11 @@
 	static const char *help =
 		"Usage: vpddecode [OPTIONS]\n"
 		"Options are:\n"
-		" -d, --dev-mem FILE     Read memory from device FILE (default: " DEFAULT_MEM_DEV ")\n"
+		" -d, --dev-mem FILE     Read memory from device FILE (default: %s)\n"
 		" -h, --help             Display this help text and exit\n"
 		" -s, --string KEYWORD   Only display the value of the given VPD string\n"
 		" -u, --dump             Do not decode the VPD records\n"
 		" -V, --version          Display the version and exit\n";
 
-	printf("%s", help);
+	printf(help, DEFAULT_MEM_DEV);
 }
