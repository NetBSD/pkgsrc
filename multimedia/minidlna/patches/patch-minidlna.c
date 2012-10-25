$NetBSD: patch-minidlna.c,v 1.2 2012/10/25 10:25:27 drochner Exp $

--- minidlna.c.orig	2012-05-08 00:10:42.000000000 +0000
+++ minidlna.c
@@ -52,6 +52,7 @@
 #include <stdio.h>
 #include <ctype.h>
 #include <sys/types.h>
+#include <sys/stat.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
@@ -65,6 +66,10 @@
 #include <pthread.h>
 #include <pwd.h>
 
+#include <err.h>
+#include <stdint.h>
+#include <sysexits.h>
+
 #include "config.h"
 
 #ifdef ENABLE_NLS
@@ -85,7 +90,9 @@
 #include "daemonize.h"
 #include "upnpevents.h"
 #include "scanner.h"
+#ifdef __linux__
 #include "inotify.h"
+#endif
 #include "log.h"
 #ifdef TIVO_SUPPORT
 #include "tivo_beacon.h"
@@ -115,7 +122,7 @@ OpenAndConfHTTPSocket(unsigned short por
 		return -1;
 	}
 
-	if(setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(i)) < 0)
+	if(setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &i, sizeof(i)) < 0)
 	{
 		DPRINTF(E_WARN, L_GENERAL, "setsockopt(http, SO_REUSEADDR): %s\n", strerror(errno));
 	}
@@ -343,7 +350,7 @@ init(int argc, char * * argv)
 	int options_flag = 0;
 	struct sigaction sa;
 	const char * presurl = NULL;
-	const char * optionsfile = "/etc/minidlna.conf";
+	const char * optionsfile = "@PKG_SYSCONFDIR@/minidlna.conf";
 	char mac_str[13];
 	char * string, * word;
 	enum media_types type;
@@ -353,6 +360,7 @@ init(int argc, char * * argv)
 	char log_str[72] = "general,artwork,database,inotify,scanner,metadata,http,ssdp,tivo=warn";
 	char *log_level = NULL;
 
+	uid_t	uid = (uid_t)-1;
 	/* first check if "-f" option is used */
 	for(i=2; i<argc; i++)
 	{
@@ -741,10 +749,28 @@ init(int argc, char * * argv)
 			printf("Version " MINIDLNA_VERSION "\n");
 			exit(0);
 			break;
+		case 'u':
+			if(i+1 == argc)
+				err(EX_USAGE, "Option -%c takes one argument.", argv[i][1]);
+			else {
+				char *endp;
+				i++;
+				uid = strtol(argv[i], &endp, 0);
+				if (*endp) {
+					/* Symbolic username given, not UID. */
+					struct passwd *entry = getpwnam(argv[i]);
+
+					if (entry == NULL)
+						err(EX_NOUSER, "%s", argv[i]);
+					uid = entry->pw_uid;
+				}
+			}
+			break;
 		default:
 			DPRINTF(E_ERROR, L_GENERAL, "Unknown option: %s\n", argv[i]);
 		}
 	}
+#if 0
 	/* If no IP was specified, try to detect one */
 	if( n_lan_addr < 1 )
 	{
@@ -753,6 +779,7 @@ init(int argc, char * * argv)
 			DPRINTF(E_FATAL, L_GENERAL, "No IP address automatically detected!\n");
 		}
 	}
+#endif
 
 	if( (n_lan_addr==0) || (runtime_vars.port<=0) )
 	{
@@ -762,6 +789,7 @@ init(int argc, char * * argv)
 			/*"[-l logfile] " not functionnal */
 			"\t\t[-s serial] [-m model_number] \n"
 			"\t\t[-t notify_interval] [-P pid_filename]\n"
+			"\t\t[-u uid_to_run_as]\n"
 			"\t\t[-w url] [-R] [-V] [-h]\n"
 		        "\nNotes:\n\tNotify interval is in seconds. Default is 895 seconds.\n"
 			"\tDefault pid file is %s.\n"
@@ -834,6 +862,9 @@ init(int argc, char * * argv)
 
 	writepidfile(pidfilename, pid);
 
+	if (uid != (uid_t)-1 && setuid(uid) == -1)
+		err(EX_NOPERM, "setuid(%ld)", (long)uid);
+
 	return 0;
 }
 
@@ -960,6 +991,7 @@ main(int argc, char * * argv)
 #endif
 	}
 	signal(SIGCHLD, SIG_IGN);
+#if defined(__linux__)
 	if( sqlite3_threadsafe() && sqlite3_libversion_number() >= 3005001 &&
 	    GETFLAG(INOTIFY_MASK) && pthread_create(&inotify_thread, NULL, start_inotify, NULL) )
 	{
@@ -971,8 +1003,9 @@ main(int argc, char * * argv)
 		DPRINTF(E_INFO, L_GENERAL, "Enabled interface %s/%s\n",
 		        lan_addr[i].str, inet_ntoa(lan_addr[i].mask));
 	}
+#endif
 
-	sudp = OpenAndConfSSDPReceiveSocket(n_lan_addr, lan_addr);
+	sudp = OpenAndConfSSDPReceiveSocket();
 	if(sudp < 0)
 	{
 		DPRINTF(E_INFO, L_GENERAL, "Failed to open socket for receiving SSDP. Trying to use MiniSSDPd\n");
