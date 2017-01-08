# $NetBSD: options.mk,v 1.1 2017/01/08 20:35:55 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.swaks
PKG_SUPPORTED_OPTIONS=	inet6 ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
DEPENDS+=		p5-IO-Socket-INET6-[0-9]*:../../net/p5-IO-Socket-INET6
.endif

.if !empty(PKG_OPTIONS:Mssl)
DEPENDS+=		p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay
.endif
