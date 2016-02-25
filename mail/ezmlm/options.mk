# $NetBSD: options.mk,v 1.9 2016/02/25 15:00:50 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ezmlm
PKG_SUPPORTED_OPTIONS+=	ezmlm-althash

PKG_SUGGESTED_OPTIONS.Darwin+=	ezmlm-althash

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mezmlm-althash)
USE_TOOLS+=	patch
post-patch:
	cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-althash
.endif
