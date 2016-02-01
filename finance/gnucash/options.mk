# $NetBSD: options.mk,v 1.2 2016/02/01 13:51:47 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnucash
PKG_SUPPORTED_OPTIONS=	libofx
PKG_SUGGESTED_OPTIONS=	libofx

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	ofx

.if !empty(PKG_OPTIONS:Mlibofx)
PLIST.ofx=	yes
.include "../../finance/libofx/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ofx
.endif
