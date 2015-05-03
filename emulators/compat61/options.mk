# $NetBSD: options.mk,v 1.1 2015/05/03 15:01:12 spz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.compat61
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
DEPENDS+=	compat61-x11>=6.1:../../emulators/compat61-x11
.endif
