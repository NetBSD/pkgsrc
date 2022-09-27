# $NetBSD: options.mk,v 1.1 2022/09/27 21:04:03 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-Authen-SASL
PKG_SUPPORTED_OPTIONS=	gssapi
PKG_SUGGESTED_OPTIONS=	gssapi

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgssapi)
DEPENDS+=	p5-GSSAPI-[0-9]*:../../security/p5-GSSAPI
.endif
