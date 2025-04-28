$NetBSD: patch-mbuffer.c,v 1.2 2025/04/28 11:38:37 hauke Exp $

Default sysconfdir location.

Add NetBSD support for accessing the number of available VM pages.

--- mbuffer.c.orig	2024-10-06 17:49:38.000000000 +0000
+++ mbuffer.c
@@ -46,6 +46,11 @@ typedef int caddr_t;
 #include <sys/vmmeter.h>
 #endif
 
+#ifdef __NetBSD__
+#include <sys/sysctl.h>
+#include <uvm/uvm_extern.h>
+#endif
+
 #ifdef HAVE_SENDFILE
 #ifdef HAVE_SENDFILE_H
 #include <sys/sendfile.h>
@@ -1032,6 +1037,20 @@ static void initDefaults()
 	} else {
 		AvP = vmt.t_free;
 	}
+#elif defined(__NetBSD__)
+	/* lifted from src/usr.bin/vmstat/vmstat.c, see also PR kern/49266 */
+	struct vmtotal total;
+	size_t size;
+	const int vmmeter_mib[] = { CTL_VM, VM_METER };
+
+	size = sizeof(total);
+	if (sysctl(vmmeter_mib, __arraycount(vmmeter_mib),
+		&total, &size, NULL, 0) == -1) {
+		warningmsg("unable to determine number of available pages: %s\n", strerror(errno));
+		AvP = 0;
+	} else {
+		AvP = total.t_free;
+	}
 #else
 	warningmsg("no mechanism to determine number of available pages\n",strerror(errno));
 #endif
@@ -1060,7 +1079,7 @@ static void initDefaults()
 
 	const char *home = getenv("HOME");
 	readConfigFile("/etc/mbuffer.rc");
-	readConfigFile(PREFIX "/etc/mbuffer.rc");
+	readConfigFile(SYSCONFDIR "/mbuffer.rc");
 	if (home == 0) {
 		warningmsg("HOME environment variable not set - unable to find defaults file\n");
 		return;
