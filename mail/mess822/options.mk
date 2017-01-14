# $NetBSD: options.mk,v 1.1 2017/01/14 20:49:07 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mess822
PKG_SUPPORTED_OPTIONS+=	sasl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
SMTPAUTH_PATCH=	mess822-smtp-auth-patch.txt
PATCHFILES+=		${SMTPAUTH_PATCH}
SITES.${SMTPAUTH_PATCH}=	http://qmail.gurus.org/
PATCH_DIST_STRIP.${SMTPAUTH_PATCH}=	-p1
.endif
