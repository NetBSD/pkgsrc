$NetBSD: patch-external_postgresql_ExternalProject__postgresql.mk,v 1.4 2021/03/06 04:19:35 ryoon Exp $

* Do not try to link NSPR/NSS libraries. They are not required really.

--- external/postgresql/ExternalProject_postgresql.mk.orig	2021-02-25 12:19:22.000000000 +0000
+++ external/postgresql/ExternalProject_postgresql.mk
@@ -76,7 +76,7 @@ $(call gb_ExternalProject_get_state_targ
 			CFLAGS="-fPIC" \
 			CPPFLAGS="$(postgresql_CPPFLAGS)" \
 			LDFLAGS="$(postgresql_LDFLAGS)" \
-			$(if $(ENABLE_LDAP),EXTRA_LDAP_LIBS="-llber -lssl3 -lsmime3 -lnss3 -lnssutil3 -lplds4 -lplc4 -lnspr4") \
+			$(if $(ENABLE_LDAP),EXTRA_LDAP_LIBS="-llber") \
 		&& cd src/interfaces/libpq \
 		&& MAKEFLAGS= && $(MAKE) MAKELEVEL=0 all-static-lib)
 	$(call gb_Trace_EndRange,postgresql,EXTERNAL)
