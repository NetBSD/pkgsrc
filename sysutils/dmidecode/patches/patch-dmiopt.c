$NetBSD: patch-dmiopt.c,v 1.2 2023/07/24 15:07:57 msaitoh Exp $

* Use /dev/smbios instead of /dev/mem on NetBSD if available.

--- dmiopt.c.orig	2023-03-15 01:32:17.000000000 +0900
+++ dmiopt.c	2023-07-24 13:39:41.169153661 +0900
@@ -372,7 +372,7 @@ void print_help(void)
 	static const char *help =
 		"Usage: dmidecode [OPTIONS]\n"
 		"Options are:\n"
-		" -d, --dev-mem FILE     Read memory from device FILE (default: " DEFAULT_MEM_DEV ")\n"
+		" -d, --dev-mem FILE     Read memory from device FILE (default: %s)\n"
 		" -h, --help             Display this help text and exit\n"
 		" -q, --quiet            Less verbose output\n"
 		"     --no-quirks        Decode everything without quirks\n"
@@ -386,5 +386,5 @@ void print_help(void)
 		"     --oem-string N     Only display the value of the given OEM string\n"
 		" -V, --version          Display the version and exit\n";
 
-	printf("%s", help);
+	printf(help, DEFAULT_MEM_DEV);
 }
