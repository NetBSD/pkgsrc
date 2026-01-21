# $NetBSD: options.mk,v 1.4 2026/01/21 09:18:19 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.png
PKG_SUPPORTED_OPTIONS=	apng
PKG_SUGGESTED_OPTIONS=	# do not suggest apng without consulting tech-pkg@

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mapng) || make(distinfo) || make(mdi)
APNGPATCHVERSION=		20260116
APNGPATCH=			apng-${APNGPATCHVERSION}.patch
PATCHFILES+=			${APNGPATCH}
SITES.${APNGPATCH}=		-https://hg-edge.mozilla.org/mozilla-central/raw-file/d19a323e9b878d874ee71f46f4277c68e69b7822/media/libpng/apng.patch
PATCH_DIST_STRIP.${APNGPATCH}=	-p1
.endif
