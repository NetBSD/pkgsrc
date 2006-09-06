# $NetBSD: options.mk,v 1.2 2006/09/06 22:57:21 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.amarok
PKG_SUPPORTED_OPTIONS=	libgpod mysql pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibgpod)
CONFIGURE_ARGS+=	--enable-libgpod
.include "../../audio/libgpod/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--enable-mysql
.include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--enable-postgresql
.include "../../mk/pgsql.buildlink3.mk"
.endif
