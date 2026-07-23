# $NetBSD: options.mk,v 1.1 2026/07/23 17:47:36 ktnb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gambc
PKG_SUPPORTED_OPTIONS=	javascript
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

###
###  Include JavaScript backend
###
PLIST_VARS+=		js
.if !empty(PKG_OPTIONS:Mjavascript)
CONFIGURE_ARGS+=	--enable-target=js
PLIST.js=		yes

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} bootstrap
	cd ${WRKSRC}/lib && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} univ-libs

.endif
