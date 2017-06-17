# $NetBSD: options.mk,v 1.3 2017/06/17 05:58:39 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qmail-run
PKG_SUPPORTED_OPTIONS+=	sasl tls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
DEPENDS+=		spamdyke-[0-9]*:../../mail/spamdyke
.endif

.if !empty(PKG_OPTIONS:Mtls)
DEPENDS+=		stunnel-[0-9]*:../../security/stunnel
.endif
