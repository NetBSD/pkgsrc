# $NetBSD: options.mk,v 1.3 2026/01/21 09:14:43 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.png
PKG_SUPPORTED_OPTIONS=	apng
PKG_SUGGESTED_OPTIONS=	# do not suggest apng without consulting tech-pkg@

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mapng) || make(distinfo) || make(mdi)
APNGPATCHVERSION=		20260120
APNGPATCH=			apng-${APNGPATCHVERSION}.patch
PATCHFILES+=			${APNGPATCH}
SITES.${APNGPATCH}=		-https://hg-edge.mozilla.org/mozilla-central/raw-file/f0b42fcd1bcab924abe3b603e759d7bd9fb8ee97/media/libpng/apng.patch
PATCH_DIST_STRIP.${APNGPATCH}=	-p1
.endif
