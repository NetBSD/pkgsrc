# $NetBSD: options.mk,v 1.2 2024/08/25 06:19:07 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libzrtpcpp
PKG_SUPPORTED_OPTIONS=	sqlite3
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite3)
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.7
.include "../../databases/sqlite3/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=		-DSQLITE=ON
.else
CMAKE_CONFIGURE_ARGS+=		-DSQLITE=OFF
.endif
