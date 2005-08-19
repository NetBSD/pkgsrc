# $NetBSD: options.mk,v 1.4 2005/08/19 04:44:09 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ezmlm
PKG_SUPPORTED_OPTIONS+=	ezmlm-althash
PKG_OPTIONS_LEGACY_OPTS+=	althash:ezmlm-althash

.if ${OPSYS} == "Darwin"
PKG_SUGGESTED_OPTIONS=	ezmlm-althash
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mezmlm-althash)
post-patch:
	@cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-althash
.endif
