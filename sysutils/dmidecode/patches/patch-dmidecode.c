$NetBSD: patch-dmidecode.c,v 1.1 2018/10/23 10:16:12 jmcneill Exp $

Find SMBIOS table address on NetBSD ARM64.

--- dmidecode.c.orig	2018-10-23 09:59:50.281527237 +0000
+++ dmidecode.c
@@ -72,6 +72,12 @@
 #include <kenv.h>
 #endif
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <errno.h>
+#endif
+
 #include "version.h"
 #include "config.h"
 #include "types.h"
@@ -5463,6 +5469,9 @@ static int address_from_efi(off_t *addre
 	char linebuf[64];
 #elif defined(__FreeBSD__)
 	char addrstr[KENV_MVALLEN + 1];
+#elif defined(__NetBSD__)
+	uint64_t addr;
+	size_t addrlen;
 #endif
 	const char *eptype;
 	int ret;
@@ -5516,6 +5525,23 @@ static int address_from_efi(off_t *addre
 	*address = strtoull(addrstr, NULL, 0);
 	eptype = "SMBIOS";
 	ret = 0;
+#elif defined(__NetBSD__)
+	/*
+	 * On NetBSD, SMBIOS anchor base address on non-x86 is exposed
+	 * via sysctl.
+	 */ 
+	addrlen = sizeof(addr);
+	ret = sysctlbyname("machdep.smbios", &addr, &addrlen, NULL, 0);
+	if (ret == -1)
+	{
+		if (errno != ENOENT)
+			perror("sysctlbyname");
+		return EFI_NOT_FOUND;
+	}
+
+	*address = (off_t)addr;
+	eptype = "SMBIOS";
+	ret = 0;
 #else
 	ret = EFI_NOT_FOUND;
 #endif
