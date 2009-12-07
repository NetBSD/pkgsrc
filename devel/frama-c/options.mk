# $NetBSD: options.mk,v 1.1 2009/12/07 16:39:12 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.frama-c
PKG_SUPPORTED_OPTIONS=	gnomecanvas
# actually, depends completely on lablgtk's gnomecanvas option
# but I didn't manage to check for that.
PKG_SUGGESTED_OPTIONS=	gnomecanvas

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnomecanvas)
PLIST_SRC+=	PLIST.gnomecanvas
.endif
