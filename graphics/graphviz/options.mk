# $NetBSD: options.mk,v 1.17 2013/03/16 22:41:50 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.graphviz
PKG_SUPPORTED_OPTIONS=	gd ghostscript gtk guile lua ocaml pangocairo rsvg tcl x11 perl
PKG_SUGGESTED_OPTIONS=	gd gtk lua pangocairo perl tcl x11
# Explanation of consequence of options, to help those trying to slim down:
#   guile ocaml lua tcl perl: extension language support
#   x11: Omits all linking with x11, which means x11 graphics supports as
#     well as x11 frontend support.
#   pangocairo: basic ps/pdf support.
#   gtk: basic graphic format support (in addition to gd, which isn't
#     maintained anymore)
#   rsvg: Omitting loses svg support. librsvg has large dependencies
#     including some GNOME libs.
#   gd: basic graphic format support, especially gif
#   ghostscript: provides better ps/pdf-support, plus eps

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gd ghostscript gtk guile lua ocaml pangocairo perl rsvg tcl x11

.if !empty(PKG_OPTIONS:Mx11)
.include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ENV+=		X11PREFIX=${X11PREFIX} X11BASE=${X11BASE}
PLIST.x11=		yes

.  if !empty(PKG_OPTIONS:Mpangocairo)
.  include "../../devel/pango/buildlink3.mk"
.  include "../../graphics/cairo/buildlink3.mk"
PLIST.pangocairo=	yes

.    if !empty(PKG_OPTIONS:Mghostscript)
.    include "../../print/ghostscript/ghostscript.buildlink3.mk"
PLIST.ghostscript=	yes
.    else
CONFIGURE_ARGS+=	--without-ghostscript
.    endif

.    if !empty(PKG_OPTIONS:Mgtk)
.    include "../../x11/gtk2/buildlink3.mk"
PLIST.gtk=		yes
.    else
CONFIGURE_ARGS+=	--without-gdk-pixbuf
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-gnomeui
.    endif

.    if !empty(PKG_OPTIONS:Mrsvg)
.    include "../../graphics/librsvg/buildlink3.mk"
PLIST.rsvg=		yes
.    else
CONFIGURE_ARGS+=	--without-rsvg
.    endif

.  else
# + x11, -pangocairo
CONFIGURE_ARGS+=	--without-pangocairo

.    if !empty(PKG_OPTIONS:Mghostscript)
PKG_FAIL_REASON+=	"option ghostscript needs option pangocairo"
.    endif
CONFIGURE_ARGS+=	--without-ghostscript

.    if !empty(PKG_OPTIONS:Mgtk)
PKG_FAIL_REASON+=	"option gtk needs option pangocairo"
.    endif
CONFIGURE_ARGS+=	--without-gdk-pixbuf
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-gnomeui

.    if !empty(PKG_OPTIONS:Mrsvg)
PKG_FAIL_REASON+=	"option rsvg needs option pangocairo"
.    endif
CONFIGURE_ARGS+=	--without-rsvg
.  endif

.else
# - x11
CONFIGURE_ARGS+=	--without-x

.  if !empty(PKG_OPTIONS:Mpangocairo)
PKG_FAIL_REASON+=	"option pangocairo needs option x11"
.  endif
CONFIGURE_ARGS+=	--without-pangocairo

.  if !empty(PKG_OPTIONS:Mghostscript)
PKG_FAIL_REASON+=	"option ghostscript needs option pangocairo and x11"
.  endif
CONFIGURE_ARGS+=	--without-ghostscript

.  if !empty(PKG_OPTIONS:Mgtk)
PKG_FAIL_REASON+=	"option gtk needs option pangocairo and x11"
.  endif
CONFIGURE_ARGS+=	--without-gdk-pixbuf
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-gnomeui

.  if !empty(PKG_OPTIONS:Mrsvg)
PKG_FAIL_REASON+=	"option rsvg needs option pangocairo and x11"
.  endif
CONFIGURE_ARGS+=	--without-rsvg
.endif

.if !empty(PKG_OPTIONS:Mgd)
.include "../../graphics/gd/buildlink3.mk"
PLIST.gd=		yes
.else
CONFIGURE_ARGS+=	--without-libgd
CONFIGURE_ARGS+=	--without-mylibgd
.endif

USING_SWIG=	no

.if !empty(PKG_OPTIONS:Mlua)
USING_SWIG=	yes
.include "../../lang/lua/buildlink3.mk"
PLIST.lua=		yes
.else
CONFIGURE_ARGS+=	--disable-lua
.endif

.if !empty(PKG_OPTIONS:Mocaml)
USING_SWIG=	yes
.include "../../lang/ocaml/buildlink3.mk"
PLIST.ocaml=		yes
.else
CONFIGURE_ARGS+=	--disable-ocaml
.endif

.if !empty(PKG_OPTIONS:Mtcl)
USING_SWIG=	yes
.include "../../lang/tcl/Makefile.version"
.include "../../x11/tk/buildlink3.mk"
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
.include "../../lang/guile/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-guile
PLIST.guile=		yes
.else
CONFIGURE_ARGS+=	--disable-guile
.endif

.if !empty(PKG_OPTIONS:Mperl)
USING_SWIG=	yes
.include "../../lang/perl5/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-perl
PLIST.perl=		yes
USE_TOOLS+=perl
.else
CONFIGURE_ARGS+=	--disable-perl
.endif

.if !empty(USING_SWIG:Myes)
.include "../../devel/swig/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-swig
.endif
