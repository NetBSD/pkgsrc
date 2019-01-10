# $NetBSD: options.mk,v 1.2 2019/01/10 13:23:16 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qmail-conf
PKG_SUPPORTED_OPTIONS+=	inet6 pam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
DEPENDS+=		ucspi-tcp6-[0-9]*:../../net/ucspi-tcp6
.else
DEPENDS+=		{ucspi-tcp6-[0-9]*,ucspi-tcp-[0-9]*}:../../net/ucspi-tcp
.endif

.if !empty(PKG_OPTIONS:Mpam)
DEPENDS+=		checkpassword-pam-[0-9]*:../../sysutils/checkpassword-pam
.else
DEPENDS+=		checkpassword-[0-9]*:../../sysutils/checkpassword
.endif
