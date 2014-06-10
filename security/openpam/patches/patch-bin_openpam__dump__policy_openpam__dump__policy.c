$NetBSD: patch-bin_openpam__dump__policy_openpam__dump__policy.c,v 1.1 2014/06/10 13:17:42 joerg Exp $

--- bin/openpam_dump_policy/openpam_dump_policy.c.orig	2013-09-07 13:28:00.000000000 +0000
+++ bin/openpam_dump_policy/openpam_dump_policy.c
@@ -64,7 +64,7 @@ openpam_facility_index_name(pam_facility
 	if (asprintf(&name, "PAM_%s", facility) == -1)
 		return (NULL);
 	for (p = name + 4; *p; ++p)
-		*p = toupper(*p);
+		*p = toupper((unsigned char)*p);
 	return (name);
 }
 
