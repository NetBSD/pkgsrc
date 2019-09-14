# $NetBSD: options.mk,v 1.4 2019/09/14 18:57:10 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.balsa
PKG_SUPPORTED_OPTIONS=	compface ldap sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcompface)
CONFIGURE_ARGS+=	--with-compface
.  include "../../graphics/compface/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=	--with-sqlite
.  include "../../databases/sqlite3/buildlink3.mk"
.endif
