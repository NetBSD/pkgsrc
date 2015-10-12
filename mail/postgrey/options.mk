# $NetBSD: options.mk,v 1.2 2015/10/12 11:10:34 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.postgrey
PKG_SUPPORTED_OPTIONS=	postgrey-targrey

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpostgrey-targrey)
# See http://k2net.hakuba.jp/targrey/index.en.html
PATCHFILES+=		targrey-0.31-postgrey-1.34.patch
PATCH_SITES=		http://k2net.hakuba.jp/pub/
PATCH_DIST_STRIP=	-p0
.endif
