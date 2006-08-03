# $NetBSD: options.mk,v 1.1.1.1 2006/08/03 15:09:49 salo Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.kismet
PKG_SUPPORTED_OPTIONS=	gps
PKG_SUGGESTED_OPTIONS=	gps

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgps)
PLIST_SRC+=		PLIST.gps
DEPENDS+=		wget>=1.9.1:../../net/wget
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.endif
