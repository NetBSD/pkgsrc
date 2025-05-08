# $NetBSD: options.mk,v 1.2 2025/05/08 10:39:45 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.png
PKG_SUPPORTED_OPTIONS=	apng
PKG_SUGGESTED_OPTIONS=	# do not suggest apng without consulting tech-pkg@

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mapng) || make(distinfo) || make(mdi)
APNGPATCHVERSION=		20250220
APNGPATCH=			apng-${APNGPATCHVERSION}.patch
PATCHFILES+=			${APNGPATCH}
SITES.${APNGPATCH}=		-https://hg-edge.mozilla.org/mozilla-central/raw-file/1a06aa3c2aab3bdd600869ffa8831c56093c699f/media/libpng/apng.patch
PATCH_DIST_STRIP.${APNGPATCH}=	-p1
.endif
