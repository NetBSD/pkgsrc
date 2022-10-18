$NetBSD: patch-agent_mibgroup_mibII_interfaces.c,v 1.1 2022/10/18 12:01:52 adam Exp $

Some systems define ifnet.if_lastchange as struct timespec (with a
tv_nsec field measured in nanoseconds), while other systems define it
as struct timeval (with a tv_usec field measured in microseconds).
Both variants have a tv_sec field for integer seconds.

--- agent/mibgroup/mibII/interfaces.c.orig	2012-10-09 22:28:58.000000000 +0000
+++ agent/mibgroup/mibII/interfaces.c
@@ -871,15 +871,25 @@ var_ifEntry(struct variable *vp,
          * * this is fixed, thus the 199607 comparison.
          */
         if (ifnet.if_lastchange.tv_sec == 0 &&
-            ifnet.if_lastchange.tv_usec == 0)
+#if HAVE_STRUCT_IFNET_IF_LASTCHANGE_TV_NSEC
+            ifnet.if_lastchange.tv_nsec == 0
+#else
+            ifnet.if_lastchange.tv_usec == 0
+#endif
+	)
             long_return = 0;
         else if (ifnet.if_lastchange.tv_sec < starttime.tv_sec)
             long_return = 0;
         else {
             long_return = (u_long)
                 ((ifnet.if_lastchange.tv_sec - starttime.tv_sec) * 100
-                 + (ifnet.if_lastchange.tv_usec -
-                    starttime.tv_usec) / 10000);
+                 + (
+#if HAVE_STRUCT_IFNET_IF_LASTCHANGE_TV_NSEC
+		    ifnet.if_lastchange.tv_nsec / 1000
+#else
+		    ifnet.if_lastchange.tv_usec
+#endif
+		    - starttime.tv_usec) / 10000);
         }
 #else
 #if NETSNMP_NO_DUMMY_VALUES
