# $NetBSD: options.mk,v 1.1 2015/01/31 18:41:01 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnucash
PKG_SUPPORTED_OPTIONS=	libofx
PKG_SUGGESTED_OPTIONS=	libofx

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	ofx

.if !empty(PKG_OPTIONS:Mglibofx)
.include "../../finance/libofx/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ofx
.endif
