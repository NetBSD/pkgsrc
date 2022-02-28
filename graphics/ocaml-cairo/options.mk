# $NetBSD: options.mk,v 1.1 2022/02/28 12:55:08 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-cairo
PKG_SUPPORTED_OPTIONS=	gtk pango
PKG_SUGGESTED_OPTIONS=	gtk pango

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gtk pango

###
### gtk support
###
.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/ocaml-lablgtk/buildlink3.mk"
PLIST.gtk=	yes
OCAML_FINDLIB_DIRS+=	cairo2-gtk
USE_TOOLS+=	pkg-config
.endif

###
### pango support
###
.if !empty(PKG_OPTIONS:Mpango)
.include "../../x11/ocaml-lablgtk/buildlink3.mk"
PLIST.pango=	yes
OCAML_FINDLIB_DIRS+=	cairo2-pango
.endif
