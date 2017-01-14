# $NetBSD: options.mk,v 1.1 2017/01/14 23:00:31 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qmail-run
PKG_SUPPORTED_OPTIONS+=	sasl tls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
DEPENDS+=		spamdyke-[0-9]*:../../mail/spamdyke
.endif

.if !empty(PKG_OPTIONS:Mtls)
DEPENDS+=		stunnel-[0-9]*:../../security/stunnel
.endif
