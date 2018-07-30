# $NetBSD: options.mk,v 1.1 2018/07/30 00:02:39 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.daemontools-run
PKG_SUPPORTED_OPTIONS+=		inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
DEPENDS+=			ucspi-tcp6-[0-9]*:../../net/ucspi-tcp6
.else
DEPENDS+=			ucspi-tcp-[0-9]*:../../net/ucspi-tcp
.endif
