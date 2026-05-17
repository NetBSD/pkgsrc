# $NetBSD: options.mk,v 1.5 2026/05/17 13:45:31 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.png
PKG_SUPPORTED_OPTIONS=	apng
PKG_SUGGESTED_OPTIONS=	# do not suggest apng without consulting tech-pkg@

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mapng) || make(distinfo) || make(mdi)
APNGPATCHVERSION=		1.6.58
APNGPATCH=			libpng-${APNGPATCHVERSION}-apng.patch.gz
PATCHFILES+=			${APNGPATCH}
SITES.${APNGPATCH}=		${MASTER_SITE_SOURCEFORGE:=libpng-apng/libpng16/${APNGPATCHVERSION}/}
PATCH_DIST_STRIP.${APNGPATCH}=	-p1
.endif
