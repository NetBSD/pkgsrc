# $NetBSD: options.mk,v 1.2 2007/11/29 17:05:35 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.libiconv
PKG_SUPPORTED_OPTIONS=	libiconv-cp932
PKG_SUGGESTED_OPTIONS=	libiconv-cp932

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibiconv-cp932)
PATCH_SITES=	http://www2d.biglobe.ne.jp/~msyk/software/libiconv/
PATCHFILES=	libiconv-1.12-cp932.patch.gz
PATCH_DIST_STRIP=	-p1
.endif
