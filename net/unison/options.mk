# $NetBSD: options.mk,v 1.1 2006/12/11 23:00:31 tonio Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unison
PKG_SUPPORTED_OPTIONS=	lablgtk2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlablgtk2)
MAKE_FLAGS+=	UISTYLE=gtk2
.include "../../x11/lablgtk2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.else
MAKE_FLAGS+=	UISTYLE=text
.endif
