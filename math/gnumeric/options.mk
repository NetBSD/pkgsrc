# $NetBSD: options.mk,v 1.1 2012/06/02 07:10:53 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnumeric
PKG_SUPPORTED_OPTIONS=	psiconv

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpsiconv)
.include "../../converters/psiconv/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-psiconv
.endif
