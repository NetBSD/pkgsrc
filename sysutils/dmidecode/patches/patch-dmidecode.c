$NetBSD: patch-dmidecode.c,v 1.3 2022/04/23 20:18:30 tnn Exp $

* Find SMBIOS table address on NetBSD ARM64.
* Add missing header for FreeBSD.
* Subject: dmidecode: Fix the condition error in ascii_filter
  https://git.savannah.gnu.org/cgit/dmidecode.git/patch/?id=1117390ccd9cea139638db6f460bb6de70e28f94
* Subject: dmidecode: Fix crash with -u option
  https://git.savannah.gnu.org/cgit/dmidecode.git/patch/?id=11e134e54d15e67a64c39a623f492a28df922517

--- dmidecode.c.orig	2020-10-14 12:51:11.000000000 +0000
+++ dmidecode.c
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
@@ -116,7 +123,7 @@ static void ascii_filter(char *bp, size_
 	size_t i;
 
 	for (i = 0; i < len; i++)
-		if (bp[i] < 32 || bp[i] == 127)
+		if (bp[i] < 32 || bp[i] >= 127)
 			bp[i] = '.';
 }
 
@@ -248,9 +255,9 @@ static void dmi_dump(const struct dmi_he
 			{
 				int j, l = strlen(s) + 1;
 
-				off = 0;
 				for (row = 0; row < ((l - 1) >> 4) + 1; row++)
 				{
+					off = 0;
 					for (j = 0; j < 16 && j < l - (row << 4); j++)
 						off += sprintf(raw_data + off,
 						       j ? " %02X" : "%02X",
@@ -5499,6 +5506,9 @@ static int address_from_efi(off_t *addre
 	char linebuf[64];
 #elif defined(__FreeBSD__)
 	char addrstr[KENV_MVALLEN + 1];
+#elif defined(__NetBSD__)
+	uint64_t addr;
+	size_t addrlen;
 #endif
 	const char *eptype;
 	int ret;
@@ -5552,6 +5562,23 @@ static int address_from_efi(off_t *addre
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
