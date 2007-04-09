# $NetBSD: options.mk,v 1.1 2007/04/09 14:44:30 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.echoping

PKG_SUPPORTED_OPTIONS=	ldap pgsql

.include "../../mk/bsd.options.mk"

###
### OpenLDAP plugin
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
PLUGINS+=	ldap
PLIST_SRC+=	${PKGDIR}/PLIST.ldap
.endif

###
### PostgreSQL plugin
###
.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
PLUGINS+=	postgresql
PLIST_SRC+=	${PKGDIR}/PLIST.pgsql
.endif
