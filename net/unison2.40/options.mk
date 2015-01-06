# $NetBSD: options.mk,v 1.1 2015/01/06 12:57:03 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unison
PKG_SUPPORTED_OPTIONS=	lablgtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlablgtk)
MAKE_FLAGS+=	UISTYLE=gtk2
DEPENDS+=	font-schumacher-misc>=1.0:../../fonts/font-schumacher-misc
.include "../../x11/ocaml-lablgtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.else
MAKE_FLAGS+=	UISTYLE=text
.endif
