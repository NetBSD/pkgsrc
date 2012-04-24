# $NetBSD: options.mk,v 1.1 2012/04/24 20:27:18 minskim Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tex-pdftools
PKG_SUPPORTED_OPTIONS+= x11
PKG_SUGGESTED_OPTIONS+= x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
DEPENDS+=	xpdfopen-[0-9]*:../../print/xpdfopen
.endif
