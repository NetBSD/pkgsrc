# $NetBSD: options.mk,v 1.2 2017/05/27 16:58:42 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mess822
PKG_SUPPORTED_OPTIONS+=	mess822-qmailqueue sasl
PKG_SUGGESTED_OPTIONS+=	mess822-qmailqueue

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmess822-qmailqueue)
QMAILQUEUE_PATCH=		mess822-0.58-qmailqueue-20170527.patch
PATCHFILES+=			${QMAILQUEUE_PATCH}
SITES.${QMAILQUEUE_PATCH}=	https://schmonz.com/2017/05/27/
PATCH_DIST_STRIP.${QMAILQUEUE_PATCH}=	-p1
.endif

.if !empty(PKG_OPTIONS:Msasl)
SMTPAUTH_PATCH=			mess822-smtp-auth-patch.txt
PATCHFILES+=			${SMTPAUTH_PATCH}
SITES.${SMTPAUTH_PATCH}=	http://qmail.gurus.org/
PATCH_DIST_STRIP.${SMTPAUTH_PATCH}=	-p1
.endif
