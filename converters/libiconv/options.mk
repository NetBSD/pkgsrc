# $NetBSD: options.mk,v 1.1 2007/10/28 02:07:41 taca Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.libiconv
PKG_SUPPORTED_OPTIONS=	libiconv-cp932
PKG_SUGGESTED_OPTIONS=	libiconv-cp932

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibiconv-cp932)
PATCH_SITES=	http://www2d.biglobe.ne.jp/~msyk/software/libiconv/
PATCHFILES=	libiconv-1.11-cp932.patch.gz
PATCH_DIST_STRIP=	-p1
.endif
