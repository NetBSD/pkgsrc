# $NetBSD: options.mk,v 1.1 2026/10/14 08:16:41 drixter Exp $

PKG_OPTIONS_VAR=			PKG_OPTIONS.gnu-apl
PKG_SUPPORTED_OPTIONS=			gtk3 pcre x11
PKG_OPTIONS_OPTIONAL_GROUPS=		database
PKG_OPTIONS_GROUP.database=		pgsql sqlite3
PKG_SUGGESTED_OPTIONS=			pcre sqlite3

PLIST_VARS+=		gtk3


.include "../../mk/bsd.options.mk"


.if !empty(PKG_OPTIONS:Mgtk3)
USE_TOOLS+=			pkg-config
CONFIGURE_ARGS+=		--with-gtk3
PLIST.gtk3=			yes

.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.else
CONFIGURE_ARGS+=		--without-gtk3
.endif


.if !empty(PKG_OPTIONS:Mpcre)
CONFIGURE_ARGS+=		--with-pcre
.include "../../devel/pcre2/buildlink3.mk"

.else
CONFIGURE_ARGS+=		--without-pcre
.endif


.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=		--with-x
.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.else
CONFIGURE_ARGS+=		--without-x
.endif


.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=		--with-postgresql
.include "../../mk/pgsql.buildlink3.mk"

.else
CONFIGURE_ARGS+=		--without-postgresql
.endif


.if !empty(PKG_OPTIONS:Msqlite3)
CONFIGURE_ARGS+=		--with-sqlite3
.include "../../databases/sqlite3/buildlink3.mk"

.else
CONFIGURE_ARGS+=		--without-sqlite3
.endif
