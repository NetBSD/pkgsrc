# $NetBSD: options.mk,v 1.2 2026/08/03 13:12:23 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ii
PKG_SUPPORTED_OPTIONS=	tls
PKG_SUGGESTED_OPTIONS=	tls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtls)
PATCH_SITES=            ${HOMEPAGE}/patches/tls/
PATCHFILES+=            ${DISTNAME}-tls.diff
.  include "../../security/libretls/buildlink3.mk"
.endif
