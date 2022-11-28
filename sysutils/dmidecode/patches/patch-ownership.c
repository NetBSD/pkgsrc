$NetBSD: patch-ownership.c,v 1.1 2022/11/28 04:26:08 mrg Exp $

* Use /dev/smbios instead of /dev/mem on NetBSD if available.

--- ownership.c.orig	2022-06-27 08:06:32.000000000 -0700
+++ ownership.c	2022-11-27 14:28:45.655641133 -0800
@@ -146,11 +146,11 @@
 	static const char *help =
 		"Usage: ownership [OPTIONS]\n"
 		"Options are:\n"
-		" -d, --dev-mem FILE     Read memory from device FILE (default: " DEFAULT_MEM_DEV ")\n"
+		" -d, --dev-mem FILE     Read memory from device FILE (default: %s)\n"
 		" -h, --help             Display this help text and exit\n"
 		" -V, --version          Display the version and exit\n";
 
-	printf("%s", help);
+	printf(help, DEFAULT_MEM_DEV);
 }
 
 int main(int argc, char * const argv[])
