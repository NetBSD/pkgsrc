$NetBSD: patch-i18n_zonemeta.cpp,v 1.1.2.2 2017/11/25 09:05:15 bsiegert Exp $

Fix for CVE-2017-14952 from
http://bugs.icu-project.org/trac/changeset/40324/trunk/icu4c/source/i18n/zonemeta.cpp

--- i18n/zonemeta.cpp.orig	2017-03-14 19:39:30.000000000 +0000
+++ i18n/zonemeta.cpp
@@ -690,7 +690,6 @@ ZoneMeta::createMetazoneMappings(const U
                     mzMappings = new UVector(deleteOlsonToMetaMappingEntry, NULL, status);
                     if (U_FAILURE(status)) {
                         delete mzMappings;
-                        deleteOlsonToMetaMappingEntry(entry);
                         uprv_free(entry);
                         break;
                     }
