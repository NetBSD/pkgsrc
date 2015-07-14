# $NetBSD: options.mk,v 1.1 2015/07/14 02:36:23 minskim Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.texlive-collection-basic
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
DEPENDS+=	xdvik>=22.87:../../print/xdvik
.endif
