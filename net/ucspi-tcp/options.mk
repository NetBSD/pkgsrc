# $NetBSD: options.mk,v 1.8 2018/11/15 13:46:07 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ucspi-tcp
PKG_SUPPORTED_OPTIONS+=	ucspi-tcp-nodefaultrbl
PKG_SUGGESTED_OPTIONS+=	ucspi-tcp-nodefaultrbl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mucspi-tcp-nodefaultrbl)
NODEFAULTRBL_PATCH=		rblsmtpd-nodefaultrbl.patch
PATCHFILES+=			${NODEFAULTRBL_PATCH}
SITES.${NODEFAULTRBL_PATCH}=	http://pyropus.ca/software/misc/
PATCH_DIST_STRIP.${NODEFAULTRBL_PATCH}=	-p1
.endif
