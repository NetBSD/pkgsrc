# $NetBSD: options.mk,v 1.2 2011/11/21 19:49:19 shattered Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.amarok
PKG_SUPPORTED_OPTIONS=	libgpod libmtp mysql pgsql

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	ipod libmtp

.if !empty(PKG_OPTIONS:Mlibgpod)
PLIST.ipod=		yes
CONFIGURE_ARGS+=	--enable-libgpod
BUILDLINK_API_DEPENDS.libgpod+=	libgpod>=0.8.0
.  include "../../audio/libgpod/buildlink3.mk"
.  include "../../textproc/libplist/buildlink3.mk"
.  include "../../databases/sqlite3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibmtp)
PLIST.libmtp=		yes
.  include "../../devel/libmtp/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--enable-mysql
.  include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--enable-postgresql
.  include "../../mk/pgsql.buildlink3.mk"
.endif
