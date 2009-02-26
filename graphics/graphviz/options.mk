# $NetBSD: options.mk,v 1.5 2009/02/26 19:45:14 sno Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.graphviz
PKG_SUPPORTED_OPTIONS=	x11 pangocairo guile lua ocaml swig tcl gtk gd
PKG_SUGGESTED_OPTIONS=	x11 pangocairo lua swig tcl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		guile gtk lua ocaml tcl pangocairo x11 gd

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libXp/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ENV+=		X11PREFIX=${X11PREFIX} X11BASE=${X11BASE}
PLIST.x11=		yes
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if !empty(PKG_OPTIONS:Mx11) && !empty(PKG_OPTIONS:Mguile)
.include "../../lang/guile/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-guile
PLIST.guile=		yes
.else
CONFIGURE_ARGS+=	--disable-guile
.endif

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
PLIST.lua=		yes
.else
CONFIGURE_ARGS+=	--disable-lua
.endif

.if !empty(PKG_OPTIONS:Mocaml)
.include "../../lang/ocaml/buildlink3.mk"
PLIST.ocaml=		yes
.else
CONFIGURE_ARGS+=	--disable-ocaml
.endif

.if !empty(PKG_OPTIONS:Mswig)
.include "../../devel/swig/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-swig
.endif

.if !empty(PKG_OPTIONS:Mtcl)
.include "../../x11/tk/buildlink3.mk"
CONFIGURE_ENV+=		TCLCONFIG=${TCLCONFIG_SH:Q}
CONFIGURE_ENV+=		TKCONFIG=${TKCONFIG_SH:Q}
PLIST.tcl=		yes
.else
CONFIGURE_ARGS+=	--disable-tcl
.endif

.if !empty(PKG_OPTIONS:Mx11) && !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk2/buildlink3.mk"
PLIST.gtk=		yes
.else
CONFIGURE_ARGS+=	--without-gdk-pixbuf
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-gnomeui
.endif

.if !empty(PKG_OPTIONS:Mgd)
.include "../../graphics/gd/buildlink3.mk"
PLIST.gd=		yes
.else
CONFIGURE_ARGS+=	--without-libgd
.endif

.if !empty(PKG_OPTIONS:Mx11) && !empty(PKG_OPTIONS:Mpangocairo)
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
PLIST.pangocairo=		yes
.else
CONFIGURE_ARGS+=	--without-pangocairo
.endif
