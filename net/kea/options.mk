# $NetBSD: options.mk,v 1.3 2025/10/28 15:09:55 taca Exp $

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
MESON_ARGS+=	-Dpostgresql=enabled
PLIST.pgsql=	yes
.  include "../../mk/pgsql.buildlink3.mk"
.else
MESON_ARGS+=	-Dpostgresql=disabled
.endif

.if !empty(PKG_OPTIONS:Mmysql)
MESON_ARGS+=	-Dmysql=enabled
PLIST.mysql=	yes
.  include "../../mk/mysql.buildlink3.mk"
.else
MESON_ARGS+=	-Dmysql=disabled
.endif
