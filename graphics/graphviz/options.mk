# $NetBSD: options.mk,v 1.1 2008/02/06 18:56:52 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.graphviz
PKG_SUPPORTED_OPTIONS=	guile lua ocaml swig tcl gtk
PKG_SUGGESTED_OPTIONS=	lua swig tcl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mguile)
.include "../../lang/guile/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-guile
.else
CONFIGURE_ARGS+=	--disable-guile
.endif

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
PLIST_SUBST+=		LUA=
.else
CONFIGURE_ARGS+=	--disable-lua
PLIST_SUBST+=		LUA="@comment "
.endif

.if !empty(PKG_OPTIONS:Mocaml)
.include "../../lang/ocaml/buildlink3.mk"
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
PLIST_SUBST+=		TCL=
.else
CONFIGURE_ARGS+=	--disable-tcl
PLIST_SUBST+=		TCL="@comment "
.endif

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk2/buildlink3.mk"
PLIST_SUBST+=		GTK=
.else
CONFIGURE_ARGS+=	--without-gdk-pixbuf
CONFIGURE_ARGS+=	--without-gtk
PLIST_SUBST+=		GTK="@comment "
.endif
