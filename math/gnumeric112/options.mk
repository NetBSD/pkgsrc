# $NetBSD: options.mk,v 1.1 2013/03/14 19:00:45 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnumeric
PKG_SUPPORTED_OPTIONS=	psiconv

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpsiconv)
.include "../../converters/psiconv/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-psiconv
.endif
