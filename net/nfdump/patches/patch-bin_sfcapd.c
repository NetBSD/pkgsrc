$NetBSD: patch-bin_sfcapd.c,v 1.1 2012/07/25 21:19:30 tez Exp $

use PATH_MAX instead of MAXPATHLEN if available

--- bin/sfcapd.c.orig	2011-12-29 15:24:14.000000000 +0000
+++ bin/sfcapd.c
@@ -61,6 +61,7 @@
 #include <sys/mman.h>
 #include <string.h>
 #include <dirent.h>
+#include <limits.h>
 
 #ifdef PCAP
 #include "pcap_reader.h"
@@ -666,7 +667,12 @@ int main(int argc, char **argv) {
  
 char	*bindhost, *filter, *datadir, pidstr[32], *launch_process;
 char	*userid, *groupid, *checkptr, *listenport, *mcastgroup, *extension_tags;
-char	*Ident, *pcap_file, pidfile[MAXPATHLEN];
+char	*Ident, *pcap_file;
+#ifdef PATH_MAX
+char pidfile[PATH_MAX];
+#else
+char pidfile[MAXPATHLEN];
+#endif
 struct stat fstat;
 srecord_t	*commbuff;
 packet_function_t receive_packet;
@@ -777,18 +783,21 @@ int	c;
 				break;
 			case 'P':
 				if ( optarg[0] == '/' ) { 	// absolute path given
-					strncpy(pidfile, optarg, MAXPATHLEN-1);
+					strncpy(pidfile, optarg, sizeof(pidfile));
+					pidfile[sizeof(pidfile) - 1] = 0;
 				} else {					// path relative to current working directory
+#ifdef PATH_MAX
+					char tmp[PATH_MAX];
+#else
 					char tmp[MAXPATHLEN];
-					if ( !getcwd(tmp, MAXPATHLEN-1) ) {
+#endif
+					if ( !getcwd(tmp, sizeof(tmp)) ) {
 						fprintf(stderr, "Failed to get current working directory: %s\n", strerror(errno));
 						exit(255);
 					}
 					tmp[MAXPATHLEN-1] = 0;
-					snprintf(pidfile, MAXPATHLEN - 1 - strlen(tmp), "%s/%s", tmp, optarg);
+					snprintf(pidfile, sizeof(pidfile), "%s/%s", tmp, optarg);
 				}
-				// pidfile now absolute path
-				pidfile[MAXPATHLEN-1] = 0;
 				break;
 			case 'R': {
 				char *p = strchr(optarg, '/');
