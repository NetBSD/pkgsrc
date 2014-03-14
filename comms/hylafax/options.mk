# $NetBSD: options.mk,v 1.1 2014/03/14 15:59:29 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hylafax
PKG_SUPPORTED_OPTIONS=	pam
#pam doesn't work right now, so disabled by default
#PKG_SUGGESTED_OPTIONS=       pam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pam
.endif
