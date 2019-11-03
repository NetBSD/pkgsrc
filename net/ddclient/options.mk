# $NetBSD: options.mk,v 1.2 2019/11/03 11:45:33 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ddclient
PKG_SUPPORTED_OPTIONS=	ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

# include support for ssl
.if !empty(PKG_OPTIONS:Mssl)
DEPENDS+=	p5-IO-Socket-SSL>=2.0:../../security/p5-IO-Socket-SSL
.endif
