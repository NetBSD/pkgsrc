# $NetBSD: options.mk,v 1.2 2005/10/05 13:29:50 wiz Exp $

PKG_SUPPORTED_OPTIONS+=		pgsql-hier-query

.include "../../mk/bsd.options.mk"

###
### PAM authentication for the PostgreSQL backend.
###
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=        --with-pam
.endif

###
### Support for hierarchical queries with Oracle-like CONNECT BY syntax.
### See http://gppl.moonbone.ru/README.html for details.
###
.if !empty(PKG_OPTIONS:Mpgsql-hier-query)
PATCH_SITES=		http://gppl.moonbone.ru/
PATCHFILES=		hier-Pg8.0.3-0.5.5.diff.gz
PATCH_DIST_STRIP=	-p1
PLIST_SUBST+=		PG_HIER=
.else
PLIST_SUBST+=		PG_HIER="@comment "
.endif
