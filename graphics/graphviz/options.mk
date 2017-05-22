# $NetBSD: options.mk,v 1.24 2017/05/22 11:19:20 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.graphviz
PKG_SUPPORTED_OPTIONS=	gd ghostscript gtk gts lua ocaml poppler qt svg tcl x11 perl # guile does not build with guile20
PKG_SUGGESTED_OPTIONS=	gd gtk lua perl tcl x11
# Explanation of consequence of options, to help those trying to slim down:
#   guile ocaml lua tcl perl: extension language support
#   x11: Omits all linking with x11, which means x11 graphics supports as
#     well as x11 frontend support.
#   gtk: basic graphic format support (in addition to gd, which isn't
#     maintained anymore)
#   svg: Omitting loses svg support. librsvg has large dependencies
#     including some GNOME libs.
#   gd: basic graphic format support, especially gif
#   ghostscript: provides better ps/pdf-support, plus eps

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gd ghostscript gtk guile lua ocaml perl poppler qt svg tcl x11

.if !empty(PKG_OPTIONS:Mgd)
.  include "../../graphics/gd/buildlink3.mk"
PLIST.gd=		yes
.else
CONFIGURE_ARGS+=	--without-libgd
CONFIGURE_ARGS+=	--without-mylibgd
.endif

.if !empty(PKG_OPTIONS:Mghostscript)
.  include "../../print/ghostscript/buildlink3.mk"
PLIST.ghostscript=	yes
.else
CONFIGURE_ARGS+=	--without-ghostscript
.endif

.if !empty(PKG_OPTIONS:Mgtk)
.  include "../../x11/gtk2/buildlink3.mk"
PLIST.gtk=		yes
.else
CONFIGURE_ARGS+=	--without-gdk-pixbuf
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-gnomeui
.endif

.if !empty(PKG_OPTIONS:Mpoppler)
.  include "../../print/poppler-glib/buildlink3.mk"
PLIST.poppler=		yes
.else
CONFIGURE_ARGS+=	--without-poppler
.endif

.if !empty(PKG_OPTIONS:Mqt)
.  include "../../x11/qt4-libs/buildlink3.mk"
.  include "../../x11/qt4-tools/buildlink3.mk"
PLIST.qt=		yes
.else
CONFIGURE_ARGS+=	--without-qt
.endif

.if !empty(PKG_OPTIONS:Msvg)
.  include "../../graphics/librsvg/buildlink3.mk"
PLIST.svg=		yes
.else
CONFIGURE_ARGS+=	--without-rsvg
.endif

.if !empty(PKG_OPTIONS:Mx11)
.  include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ENV+=		X11BASE=${X11BASE}
PLIST.x11=		yes
.else
CONFIGURE_ARGS+=	--without-x
.endif

USING_SWIG=	no

.if !empty(PKG_OPTIONS:Mlua)
USING_SWIG=	yes
.  include "../../lang/lua/tool.mk"
.  include "../../lang/lua/buildlink3.mk"
PLIST.lua=		yes
.else
CONFIGURE_ARGS+=	--disable-lua
.endif

.if !empty(PKG_OPTIONS:Mocaml)
USING_SWIG=	yes
.  include "../../lang/ocaml/buildlink3.mk"
PLIST.ocaml=		yes
.else
CONFIGURE_ARGS+=	--disable-ocaml
.endif

.if !empty(PKG_OPTIONS:Mtcl)
USING_SWIG=	yes
.  include "../../lang/tcl/Makefile.version"
.  include "../../x11/tk/buildlink3.mk"
CONFIGURE_ENV+=		TCLCONFIG=${TCLCONFIG_SH:Q}
CONFIGURE_ENV+=		TKCONFIG=${TKCONFIG_SH:Q}
CONFIGURE_ARGS+=	--with-wish=${WISH}
CONFIGURE_ARGS+=	--with-tclsh=${TCLSH}
PLIST.tcl=		yes
PLIST_SUBST+=		TCL_BASEVER=${TCL_BASEVER}
.else
CONFIGURE_ARGS+=	--disable-tcl
.endif

.if !empty(PKG_OPTIONS:Mguile)
USING_SWIG=	yes
.  include "../../lang/guile20/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-guile
PLIST.guile=		yes
.else
CONFIGURE_ARGS+=	--disable-guile
.endif

.if !empty(PKG_OPTIONS:Mperl)
USING_SWIG=	yes
.  include "../../lang/perl5/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-perl
PLIST.perl=		yes
USE_TOOLS+=perl
.else
CONFIGURE_ARGS+=	--disable-perl
.endif

.if !empty(USING_SWIG:Myes)
.  include "../../devel/swig/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-swig
.endif
