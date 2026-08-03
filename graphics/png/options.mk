# $NetBSD: options.mk,v 1.6 2026/08/03 13:12:26 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.png
PKG_SUPPORTED_OPTIONS=	apng
PKG_SUGGESTED_OPTIONS=	# do not suggest apng without consulting tech-pkg@

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mapng) || make(distinfo) || make(mdi)
APNGPATCHVERSION=		1.6.58
APNGPATCH=			libpng-${APNGPATCHVERSION}-apng.patch.gz
PATCHFILES+=			${APNGPATCH}
SITES.${APNGPATCH}=		${MASTER_SITE_SOURCEFORGE:=libpng-apng/libpng16/${APNGPATCHVERSION}/}
.endif
