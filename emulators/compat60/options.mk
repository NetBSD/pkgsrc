# $NetBSD: options.mk,v 1.1 2013/02/17 17:24:09 spz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.compat60
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
# there are no X11 incompatibilities for netbsd-6-0 to head yet
# DEPENDS+=	compat60-x11>=6.0:../../emulators/compat60-x11
.endif
