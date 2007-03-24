# $NetBSD: options.mk,v 1.8 2007/03/24 06:30:01 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ezmlm
PKG_SUPPORTED_OPTIONS+=	ezmlm-althash

.if ${OPSYS} == "Darwin"
PKG_SUGGESTED_OPTIONS+=	ezmlm-althash
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mezmlm-althash)
USE_TOOLS+=	patch
post-patch:
	cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-althash
.endif
