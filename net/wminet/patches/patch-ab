$NetBSD: patch-ab,v 1.3 2012/05/15 14:05:01 marino Exp $

--- if.c.orig	1998-10-12 02:13:16.000000000 +0000
+++ if.c
@@ -12,12 +12,17 @@
 #include <unistd.h>
 #include <limits.h>
 #include <err.h>
+#include <errno.h>
 #include <sys/param.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 #include <net/if.h>
-#if (__FreeBSD_version >= 300003)
+#if defined(__DragonFly__)
+#define _KERNEL_STRUCTURES
+#include <net/if_var.h>
+#include <net/if_types.h>
+#elif defined(__FreeBSD_version) && __FreeBSD_version >= 300003
 #include <net/if_var.h>
 #include <net/if_types.h>
 #endif
@@ -89,7 +94,11 @@ static int addIfData(unsigned long theAd
 			if (!newData) {
 				size -= IF_STEP;
 				fprintf(stderr, "wmnet: Warning -- low memory; "
+#if defined(__NetBSD__) || defined(__DragonFly__)
+						"ignoring %s interface\n", theData->if_xname);
+#else
 						"ignoring %s interface\n", theData->if_name);
+#endif /* NetBSD */
 				return 0;
 			}
 
@@ -118,8 +127,12 @@ static int addIfData(unsigned long theAd
 		ptr->flags = 0;
 
 #ifndef NDEBUG
+#if defined(__NetBSD__) || defined(__DragonFly__)
+		printf("Added '%.*s' to list.\n", IFNAMSIZ, theData->if_xname);
+#else
 		printf("Added '%.*s%d' to list.\n", IFNAMSIZ, theData->if_name,
 			   theData->if_unit);
+#endif /* NetBSD */
 #endif
 
 		// Bump the total.
@@ -161,6 +174,7 @@ static struct ifnet const* dereference(u
 		return &d;
 	else if (sizeof(d) == kvm_read(kd, a, &d, sizeof(d))) {
 
+#if !defined(__NetBSD__) && !defined(__DragonFly__)
 		/* We've read the structure's data, but the 'name' field still
 		   points to kernel memory. We transfer the name to a local
 		   buffer, and then modify the pointer to point to our
@@ -178,6 +192,7 @@ static struct ifnet const* dereference(u
 			   to look at. While debugging, set these to NULL to trap
 			   any attempts. */
 
+#endif /* !NetBSD */
 			d.if_softc = 0;
 #if (__FreeBSD_version >= 300003)
 			d.if_addrhead.tqh_first = 0;
@@ -185,15 +200,24 @@ static struct ifnet const* dereference(u
 			d.if_addrlist = 0;
 #endif
 			d.if_bpf = 0;
+#ifdef __NetBSD__
+			d.if_addrlist.tqh_first = 0;
+#else
 			d.if_linkmib = 0;
 			d.if_poll_slowq = 0;
+#endif /* NetBSD */
 #endif
 			c = a;
 			return &d;
+#if !defined(__NetBSD__) && !defined(__DragonFly__)
 		} else
 			return 0;
+#endif /* !NetBSD */
 	} else
+	{
+		perror("kvm_read");
 		return 0;
+	}
 }
 
 /*------------------------------------------------------------------------------
@@ -233,6 +257,9 @@ int ifInit(void)
 			{ "" }
 		};
 
+	if (setgid(getgid()) != 0) { perror("setgid"); return(0); }
+	if (setuid(getuid()) != 0) { perror("seguid"); return(0); }
+
 		/* Try to pull the address for the global kernel variable,
 		   ifnet. This variable is the root of the singly-linked list
 		   of network interfaces. */
@@ -248,11 +275,15 @@ int ifInit(void)
 
 				while (current) {
 					addIfData(current);
-#if (__FreeBSD_version >= 300003)
+#if defined(__DragonFly__) || (defined(__FreeBSD_version) && __FreeBSD_version >= 300003)
 					current = (unsigned long) dereference(current)->if_link.tqe_next;
 #else
+#ifdef __NetBSD__
+					current = (unsigned long) dereference(current)->if_list.tqe_next;
+#else
 					current = (unsigned long) dereference(current)->if_next;
 #endif
+#endif
 				}
 
 				/* Try to register our termination function. If it
@@ -309,7 +340,11 @@ char const* ifName(unsigned idx)
 		if (ptr) {
 			static char buffer[IFNAMSIZ + 1];
 
+#if defined(__NetBSD__) || defined(__DragonFly__)
+			sprintf(buffer, "%.*s", IFNAMSIZ - 1, ptr->if_xname);
+#else
 			sprintf(buffer, "%.*s%d", IFNAMSIZ - 1, ptr->if_name, ptr->if_unit);
+#endif /* NetBSD */
 			return buffer;
 		}
 	}
