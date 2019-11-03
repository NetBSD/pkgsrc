# $NetBSD: options.mk,v 1.2 2019/11/03 12:04:12 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hylafax
PKG_SUPPORTED_OPTIONS=	pam
#pam doesn't work right now, so disabled by default
#PKG_SUGGESTED_OPTIONS=	pam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pam
.endif
