# $NetBSD: options.mk,v 1.1 2015/04/18 03:36:23 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libzrtpcpp
PKG_SUPPORTED_OPTIONS=	sqlite3
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite3)
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.7
.include "../../databases/sqlite3/buildlink3.mk"
CMAKE_ARGS+=		-DSQLITE=ON
.else
CMAKE_ARGS+=		-DSQLITE=OFF
.endif
