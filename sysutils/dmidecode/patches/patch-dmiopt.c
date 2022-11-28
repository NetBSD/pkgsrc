$NetBSD: patch-dmiopt.c,v 1.1 2022/11/28 04:26:08 mrg Exp $

* Use /dev/smbios instead of /dev/mem on NetBSD if available.

--- dmiopt.c.orig	2022-06-27 08:06:32.000000000 -0700
+++ dmiopt.c	2022-11-27 14:28:45.656425673 -0800
@@ -368,7 +368,7 @@
 	static const char *help =
 		"Usage: dmidecode [OPTIONS]\n"
 		"Options are:\n"
-		" -d, --dev-mem FILE     Read memory from device FILE (default: " DEFAULT_MEM_DEV ")\n"
+		" -d, --dev-mem FILE     Read memory from device FILE (default: %s)\n"
 		" -h, --help             Display this help text and exit\n"
 		" -q, --quiet            Less verbose output\n"
 		" -s, --string KEYWORD   Only display the value of the given DMI string\n"
@@ -381,5 +381,5 @@
 		"     --oem-string N     Only display the value of the given OEM string\n"
 		" -V, --version          Display the version and exit\n";
 
-	printf("%s", help);
+	printf(help, DEFAULT_MEM_DEV);
 }
