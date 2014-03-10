# $NetBSD: options.mk,v 1.1 2014/03/10 08:38:25 he Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.free42
PKG_SUPPORTED_OPTIONS=	bcd_math
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbcd_math)
MAKE_ENV+=	BCD_MATH=1
VARIANT=	dec
.else
VARIANT=	bin
.endif
