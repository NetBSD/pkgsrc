# $NetBSD: options.mk,v 1.3 2016/08/30 04:13:13 jnemeth Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnucash
PKG_SUPPORTED_OPTIONS=	libdbi libofx
PKG_SUGGESTED_OPTIONS=	libdbi libofx

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	dbi ofx

.if !empty(PKG_OPTIONS:Mlibofx)
PLIST.ofx=	yes
.include "../../finance/libofx/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ofx
.endif

.if !empty(PKG_OPTIONS:Mlibdbi)
CONFIGURE_ARGS+=	--enable-dbi
PLIST.dbi=	yes
.include "../../databases/libdbi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbi
.endif
