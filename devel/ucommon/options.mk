# $NetBSD: options.mk,v 1.1 2013/06/27 01:36:25 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ucommon
PKG_SUPPORTED_OPTIONS=	static tests
PKG_SUGGESTED_OPTIONS+=	# blank
PLIST_VARS+=		dynamic static

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mstatic)
CMAKE_ARGS+=	-DBUILD_STATIC=ON
PLIST.static=	yes
.else
CMAKE_ARGS+=	-DBUILD_STATIC=OFF
PLIST.dynamic=	yes
.endif

.if !empty(PKG_OPTIONS:Mtests)
CMAKE_ARGS+=	-DBUILD_TESTING=ON
.else
CMAKE_ARGS+=	-DBUILD_TESTING=OFF
.endif
