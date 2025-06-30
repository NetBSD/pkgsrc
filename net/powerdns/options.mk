# $NetBSD: options.mk,v 1.11 2025/06/30 11:00:50 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.powerdns
PKG_SUPPORTED_OPTIONS=	botan sqlite zeromq

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		sqlite

.if !empty(PKG_OPTIONS:Mbotan)
.include "../../devel/gmp/buildlink3.mk"
.include "../../security/botan2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msqlite)
PDNS_MODULES+=		gsqlite3
PLIST.sqlite=		yes
.include "../../databases/sqlite3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mzeromq)
CONFIGURE_ARGS+=	--enable-remotebackend-zeromq=yes
.include "../../net/zeromq/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-remotebackend-zeromq=no
.endif
