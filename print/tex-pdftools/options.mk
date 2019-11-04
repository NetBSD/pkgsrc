# $NetBSD: options.mk,v 1.2 2019/11/04 19:58:07 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tex-pdftools
PKG_SUPPORTED_OPTIONS+=	x11
PKG_SUGGESTED_OPTIONS+=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
DEPENDS+=	xpdfopen-[0-9]*:../../print/xpdfopen
.endif
