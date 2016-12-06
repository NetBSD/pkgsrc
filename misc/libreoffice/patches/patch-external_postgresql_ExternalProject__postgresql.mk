$NetBSD: patch-external_postgresql_ExternalProject__postgresql.mk,v 1.1 2016/12/06 15:21:00 ryoon Exp $

* Do not try to link NSPR/NSS libraries. They are not required really.

--- external/postgresql/ExternalProject_postgresql.mk.orig	2016-07-28 22:11:19.000000000 +0000
+++ external/postgresql/ExternalProject_postgresql.mk
@@ -60,7 +60,7 @@ $(call gb_ExternalProject_get_state_targ
 				$(if $(WITH_GSSAPI),--with-gssapi)) \
 			CPPFLAGS="$(postgresql_CPPFLAGS)" \
 			LDFLAGS="$(postgresql_LDFLAGS)" \
-			EXTRA_LDAP_LIBS="-llber -lssl3 -lsmime3 -lnss3 -lnssutil3 -lplds4 -lplc4 -lnspr4" \
+			EXTRA_LDAP_LIBS="-llber" \
 		&& cd src/interfaces/libpq \
 		&& MAKEFLAGS= && $(MAKE) all-static-lib)
 
