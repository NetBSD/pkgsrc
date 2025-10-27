# $NetBSD: options.mk,v 1.2 2025/10/27 15:46:56 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kea
PKG_SUPPORTED_OPTIONS+=	botan libyang pgsql mysql

PLIST_VARS+=	pgsql mysql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbotan)
MESON_ARGS+=	-Dcrypto=botan
.  include "../../security/botan3/buildlink3.mk"
.else
MESON_ARGS+=	-Dcrypto=openssl
.  include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibyang)
.  include "../../devel/libyang2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
MESON_ARGS+=	-Dpostgresql=enabled
PLIST.pgsql=	yes
.else
MESON_ARGS+=	-Dpostgresql=disabled
.endif

.if !empty(PKG_OPTIONS:Mmysql)
MESON_ARGS+=	-Dmysql=enabled
.  include "../../mk/mysql.buildlink3.mk"
MESON_ARGS+=	-Dmysql=disabled
PLIST.mysql=	yes
.else
.endif
