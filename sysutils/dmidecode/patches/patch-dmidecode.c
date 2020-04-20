$NetBSD: patch-dmidecode.c,v 1.2 2020/04/20 19:28:34 triaxx Exp $

* Find SMBIOS table address on NetBSD ARM64.
* Add missing header for FreeBSD.

--- dmidecode.c.orig	2020-04-20 13:13:37.626217000 +0000
+++ dmidecode.c
@@ -70,8 +70,15 @@
 #ifdef __FreeBSD__
 #include <errno.h>
 #include <kenv.h>
+#include <sys/socket.h>
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
@@ -5466,6 +5473,9 @@ static int address_from_efi(off_t *address)
 	char linebuf[64];
 #elif defined(__FreeBSD__)
 	char addrstr[KENV_MVALLEN + 1];
+#elif defined(__NetBSD__)
+	uint64_t addr;
+	size_t addrlen;
 #endif
 	const char *eptype;
 	int ret;
@@ -5517,6 +5527,23 @@ static int address_from_efi(off_t *address)
 	}
 
 	*address = strtoull(addrstr, NULL, 0);
+	eptype = "SMBIOS";
+	ret = 0;
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
 	eptype = "SMBIOS";
 	ret = 0;
 #else
