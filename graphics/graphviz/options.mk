# $NetBSD: options.mk,v 1.34 2022/07/22 12:04:46 micha Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.graphviz
PKG_SUPPORTED_OPTIONS=	gd ghostscript gtk lua perl poppler svg tcl x11
.if exists(/System/Library/Frameworks/Quartz.framework)
PKG_SUPPORTED_OPTIONS+=	quartz
.endif
PKG_SUGGESTED_OPTIONS=	gd x11
# Explanation of consequence of options, to help those trying to slim down:
#   lua tcl perl: extension language support
#   x11: Omits all linking with x11, which means x11 graphics supports as
#     well as x11 frontend support.
#   gtk: basic graphic format support (in addition to gd, which isn't
#     maintained anymore)
#   svg: Omitting loses svg support. librsvg has large dependencies
#     including some GNOME libs.
#   gd: basic graphic format support, especially gif
#   ghostscript: provides better ps/pdf-support, plus eps

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gd ghostscript gtk lua perl poppler quartz svg swig tcl x11

.if !empty(PKG_OPTIONS:Mgd)
.  include "../../graphics/gd/buildlink3.mk"
PLIST.gd=		yes
CONFIGURE_ARGS+=	--with-libgd
.else
CONFIGURE_ARGS+=	--without-libgd
.endif

.if !empty(PKG_OPTIONS:Mghostscript)
.  include "../../print/ghostscript/buildlink3.mk"
# Also required as tool dependency according to documentation
TOOL_DEPENDS+=		ghostscript-[0-9]*:../../print/ghostscript
PLIST.ghostscript=	yes
CONFIGURE_ARGS+=	--with-ghostscript
.else
CONFIGURE_ARGS+=	--without-ghostscript
.endif

.if !empty(PKG_OPTIONS:Mgtk)
.  include "../../x11/gtk2/buildlink3.mk"
PLIST.gtk=		yes
CONFIGURE_ARGS+=	--with-gdk
CONFIGURE_ARGS+=	--with-gdk-pixbuf
CONFIGURE_ARGS+=	--with-gtk
CONFIGURE_ARGS+=	--with-gnomeui
.else
CONFIGURE_ARGS+=	--without-gdk
CONFIGURE_ARGS+=	--without-gdk-pixbuf
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-gnomeui
.endif

.if !empty(PKG_OPTIONS:Mpoppler)
.  include "../../print/poppler-glib/buildlink3.mk"
PLIST.poppler=		yes
CONFIGURE_ARGS+=	--with-poppler
.else
CONFIGURE_ARGS+=	--without-poppler
.endif

.if !empty(PKG_OPTIONS:Mquartz)
PLIST.quartz=		yes
CONFIGURE_ARGS+=	--with-quartz
.else
CONFIGURE_ARGS+=	--without-quartz
.endif

.if !empty(PKG_OPTIONS:Msvg)
.  include "../../graphics/librsvg/buildlink3.mk"
PLIST.svg=		yes
CONFIGURE_ARGS+=	--with-rsvg
.else
CONFIGURE_ARGS+=	--without-rsvg
.endif

.if !empty(PKG_OPTIONS:Mx11)
.  include "../../mk/xaw.buildlink3.mk"
.  include "../../x11/libXrender/buildlink3.mk"
PLIST.x11=		yes
CONFIGURE_ENV+=		X11BASE=${X11BASE}
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

USING_SWIG=	no

.if !empty(PKG_OPTIONS:Mlua)
USING_SWIG=	yes
.  include "../../lang/lua/tool.mk"
.  include "../../lang/lua/buildlink3.mk"
.  include "../../lang/lua/application.mk"
PLIST.lua=		yes
CONFIGURE_ARGS+=	--enable-lua
.else
CONFIGURE_ARGS+=	--disable-lua
.endif

.if !empty(PKG_OPTIONS:Mtcl)
.  if empty(PKG_OPTIONS:Mx11)
PKG_FAIL_REASON=	"tcl option requires x11 option"
.  endif
USING_SWIG=	yes
.  include "../../lang/tcl/Makefile.version"
.  include "../../x11/tk/buildlink3.mk"
PLIST.tcl=		yes
PLIST_SUBST+=		TCL_BASEVER=${TCL_BASEVER}
CONFIGURE_ENV+=		TCLCONFIG=${TCLCONFIG_SH:Q}
CONFIGURE_ENV+=		TKCONFIG=${TKCONFIG_SH:Q}
CONFIGURE_ARGS+=	--with-tclsh=${TCLSH:Q}
CONFIGURE_ARGS+=	--enable-tcl
.else
CONFIGURE_ARGS+=	--disable-tcl
.endif

.if !empty(PKG_OPTIONS:Mperl)
USING_SWIG=	yes
.  include "../../lang/perl5/buildlink3.mk"
PLIST.perl=		yes
USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--enable-perl
.else
CONFIGURE_ARGS+=	--disable-perl
.endif

.if !empty(USING_SWIG:Myes)
PLIST.swig=		yes
# Tool dependency according to documentation
TOOL_DEPENDS+=		swig>=1.3.29:../../devel/swig
CONFIGURE_ARGS+=	--enable-swig
.else
CONFIGURE_ARGS+=	--disable-swig
.endif
