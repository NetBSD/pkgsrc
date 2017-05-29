# $NetBSD: options.mk,v 1.3 2017/05/29 23:20:54 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mess822
PKG_SUPPORTED_OPTIONS+=	sasl
PKG_SUGGESTED_OPTIONS+=	sasl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
SMTPAUTH_PATCH=			mess822-smtp-auth-patch.txt
PATCHFILES+=			${SMTPAUTH_PATCH}
SITES.${SMTPAUTH_PATCH}=	http://qmail.gurus.org/
PATCH_DIST_STRIP.${SMTPAUTH_PATCH}=	-p1
.endif
