# $NetBSD: options.mk,v 1.1 2013/02/17 17:24:08 spz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.compat51
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
  DEPENDS+=	compat51-x11>=5.1:../../emulators/compat51-x11
.endif
