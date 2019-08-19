# $NetBSD: options.mk,v 1.3 2019/08/19 22:11:44 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.daemontools-run
PKG_SUPPORTED_OPTIONS+=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
DEPENDS+=		ucspi-tcp6>=1.10.7nb1:../../net/ucspi-tcp6
.else
DEPENDS+=		{ucspi-tcp6>=1.10.7nb1,ucspi-tcp-[0-9]*}:../../net/ucspi-tcp
.endif
