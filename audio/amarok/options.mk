# $NetBSD: options.mk,v 1.3 2007/02/08 18:04:29 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.amarok
PKG_SUPPORTED_OPTIONS=	libgpod mysql pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibgpod)
CONFIGURE_ARGS+=	--enable-libgpod
BUILDLINK_API_DEPENDS.libgpod+=	libgpod>=0.4.2
.include "../../audio/libgpod/buildlink3.mk"
PLIST_SUBST+=	IPOD=""
.else
PLIST_SUBST+=	IPOD="@comment "
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--enable-mysql
.include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--enable-postgresql
.include "../../mk/pgsql.buildlink3.mk"
.endif
