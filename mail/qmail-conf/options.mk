# $NetBSD: options.mk,v 1.3 2023/11/16 23:09:13 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qmail-conf
PKG_SUPPORTED_OPTIONS+=	pam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
DEPENDS+=		checkpassword-pam-[0-9]*:../../sysutils/checkpassword-pam
.else
DEPENDS+=		checkpassword-[0-9]*:../../sysutils/checkpassword
.endif
