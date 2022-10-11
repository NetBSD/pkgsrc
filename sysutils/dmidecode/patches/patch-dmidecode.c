$NetBSD: patch-dmidecode.c,v 1.4 2022/10/11 09:12:18 msaitoh Exp $

* Find SMBIOS table address on NetBSD ARM64.
* Add missing header for FreeBSD.

--- dmidecode.c.orig	2022-06-28 00:06:32.000000000 +0900
+++ dmidecode.c	2022-10-11 18:08:14.158248758 +0900
@@ -71,6 +71,13 @@
 #ifdef __FreeBSD__
 #include <errno.h>
 #include <kenv.h>
+#include <sys/socket.h>
+#endif
+
+#ifdef __NetBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <errno.h>
 #endif
 
 #include "version.h"
@@ -5837,6 +5844,9 @@ static int address_from_efi(off_t *addre
 	char linebuf[64];
 #elif defined(__FreeBSD__)
 	char addrstr[KENV_MVALLEN + 1];
+#elif defined(__NetBSD__)
+	uint64_t addr;
+	size_t addrlen;
 #endif
 	const char *eptype;
 	int ret;
@@ -5890,6 +5900,23 @@ static int address_from_efi(off_t *addre
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
