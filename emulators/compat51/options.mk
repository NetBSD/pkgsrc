# $NetBSD: options.mk,v 1.2 2019/04/27 13:47:54 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.compat51
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
DEPENDS+=	compat51-x11>=5.1:../../emulators/compat51-x11
.endif
