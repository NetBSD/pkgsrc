# $NetBSD: options.mk,v 1.1 2012/12/12 12:35:21 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.minicom
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS+=	nls

PLIST_VARS+=		nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
CONFIGURE_ARGS+=	--enable-nls
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
