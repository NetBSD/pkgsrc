# $NetBSD: options.mk,v 1.3 2021/10/20 16:15:52 tm Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.postgrey
PKG_SUPPORTED_OPTIONS=	postgrey-targrey

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpostgrey-targrey)
 See http://k2net.hakuba.jp/targrey/index.en.html
PATCHFILES+=		targrey-0.31-postgrey-1.37.patch
PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCH_DIST_STRIP=	-p0
.endif
