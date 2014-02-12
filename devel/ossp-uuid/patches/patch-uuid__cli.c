$NetBSD: patch-uuid__cli.c,v 1.1 2014/02/12 11:43:53 fhajny Exp $

Preserve -m option status in -v option handling. Based on

https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=531396

--- uuid_cli.c.orig	2008-03-07 10:49:59.000000000 +0000
+++ uuid_cli.c
@@ -140,11 +140,12 @@ int main(int argc, char *argv[])
                 i = strtol(optarg, &p, 10);
                 if (*p != '\0')
                     usage("invalid argument to option 'v'");
+                version &= ~(UUID_MAKE_V1|UUID_MAKE_V3|UUID_MAKE_V4|UUID_MAKE_V5);
                 switch (i) {
-                    case 1: version = UUID_MAKE_V1; break;
-                    case 3: version = UUID_MAKE_V3; break;
-                    case 4: version = UUID_MAKE_V4; break;
-                    case 5: version = UUID_MAKE_V5; break;
+                    case 1: version |= UUID_MAKE_V1; break;
+                    case 3: version |= UUID_MAKE_V3; break;
+                    case 4: version |= UUID_MAKE_V4; break;
+                    case 5: version |= UUID_MAKE_V5; break;
                     default:
                         usage("invalid version on option 'v'");
                         break;
@@ -213,10 +214,10 @@ int main(int argc, char *argv[])
     }
     else {
         /* encoding */
-        if (   (version == UUID_MAKE_V1 && argc != 0)
-            || (version == UUID_MAKE_V3 && argc != 2)
-            || (version == UUID_MAKE_V4 && argc != 0)
-            || (version == UUID_MAKE_V5 && argc != 2))
+        if (   (version & UUID_MAKE_V1 && argc != 0)
+            || (version & UUID_MAKE_V3 && argc != 2)
+            || (version & UUID_MAKE_V4 && argc != 0)
+            || (version & UUID_MAKE_V5 && argc != 2))
             usage("invalid number of arguments");
         if ((rc = uuid_create(&uuid)) != UUID_RC_OK)
             error(1, "uuid_create: %s", uuid_error(rc));
@@ -232,7 +233,7 @@ int main(int argc, char *argv[])
                 if ((rc = uuid_load(uuid, "nil")) != UUID_RC_OK)
                     error(1, "uuid_load: %s", uuid_error(rc));
             }
-            if (version == UUID_MAKE_V3 || version == UUID_MAKE_V5) {
+            if (version & UUID_MAKE_V3 || version & UUID_MAKE_V5) {
                 if ((rc = uuid_create(&uuid_ns)) != UUID_RC_OK)
                     error(1, "uuid_create: %s", uuid_error(rc));
                 if ((rc = uuid_load(uuid_ns, argv[0])) != UUID_RC_OK) {
