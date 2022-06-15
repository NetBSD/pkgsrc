# $NetBSD: options.mk,v 1.2 2022/06/15 11:09:26 gdt Exp $

# The gtk and pango options depend on ocaml-lablgtk (which is gtk2),
# but ocaml-lablgtk3 depends on ocaml-cairo.  For now, don't suggest
# the options, as the only pkgsrc user is ocaml-lablgtk3.
PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-cairo
PKG_SUPPORTED_OPTIONS=	gtk pango
PKG_SUGGESTED_OPTIONS=

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
