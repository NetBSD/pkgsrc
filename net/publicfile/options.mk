# $NetBSD: options.mk,v 1.1 2018/07/29 23:46:21 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.publicfile
PKG_SUPPORTED_OPTIONS+=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
DEPENDS+=		ucspi-tcp6-[0-9]*:../../net/ucspi-tcp6
.else
DEPENDS+=		ucspi-tcp-[0-9]*:../../net/ucspi-tcp
.endif
