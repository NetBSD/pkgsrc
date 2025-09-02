# $NetBSD: options.mk,v 1.1 2025/09/02 20:24:02 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ii
PKG_SUPPORTED_OPTIONS=	tls
PKG_SUGGESTED_OPTIONS=	tls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtls)
PATCH_SITES=            ${HOMEPAGE}/patches/tls/
PATCHFILES+=            ${DISTNAME}-tls.diff
PATCH_DIST_STRIP=	-p1
.  include "../../security/libretls/buildlink3.mk"
.endif
