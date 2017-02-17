# $NetBSD: options.mk,v 1.3 2017/02/17 17:10:05 joerg Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.kismet
PKG_SUPPORTED_OPTIONS=	gps
PKG_SUGGESTED_OPTIONS=	gps

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgps)
PLIST_SRC+=		PLIST.gps
DEPENDS+=		wget>=1.9.1:../../net/wget
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/ImageMagick6/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif
