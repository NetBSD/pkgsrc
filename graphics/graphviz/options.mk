# $NetBSD: options.mk,v 1.39 2024/07/05 10:34:12 micha Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.graphviz
PKG_SUPPORTED_OPTIONS=	gd ghostscript lua perl poppler svg tcl x11
PKG_SUGGESTED_OPTIONS=	gd
.if exists(/System/Library/Frameworks/Quartz.framework)
PKG_SUPPORTED_OPTIONS+=	quartz
PKG_SUGGESTED_OPTIONS+=	quartz
.else
PKG_SUGGESTED_OPTIONS+=	x11
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gd ghostscript lua perl poppler quartz svg swig tcl x11

# Basic graphic format support, especially GIF
.if !empty(PKG_OPTIONS:Mgd)
.  include "../../graphics/gd/buildlink3.mk"
PLIST.gd=		yes
CONFIGURE_ARGS+=	--with-libgd
.else
CONFIGURE_ARGS+=	--without-libgd
.endif

# Better support for PS/PDF, plus EPS
.if !empty(PKG_OPTIONS:Mghostscript)
.  include "../../print/ghostscript/buildlink3.mk"
# Also required as tool dependency according to documentation
TOOL_DEPENDS+=		ghostscript-[0-9]*:../../print/ghostscript
PLIST.ghostscript=	yes
CONFIGURE_ARGS+=	--with-ghostscript
.else
CONFIGURE_ARGS+=	--without-ghostscript
.endif

# Support for reading PDF images
.if !empty(PKG_OPTIONS:Mpoppler)
BUILDLINK_API_DEPENDS.poppler+=	poppler>=23.12.0
.  include "../../print/poppler/buildlink3.mk"
PLIST.poppler=		yes
CONFIGURE_ARGS+=	--with-poppler
.else
CONFIGURE_ARGS+=	--without-poppler
.endif

# Support for Quartz on macOS
.if !empty(PKG_OPTIONS:Mquartz)
PLIST.quartz=		yes
CONFIGURE_ARGS+=	--with-quartz
.else
CONFIGURE_ARGS+=	--without-quartz
.endif

# Support for SVG images. Attention: librsvg has large dependencies!
.if !empty(PKG_OPTIONS:Msvg)
BUILDLINK_API_DEPENDS.librsvg+=	librsvg>=2.36.0
.  include "../../graphics/librsvg/buildlink3.mk"
PLIST.svg=		yes
CONFIGURE_ARGS+=	--with-rsvg
.else
CONFIGURE_ARGS+=	--without-rsvg
.endif

# X11 graphics supports as well as X11 frontend support
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

# Extension language support
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

# Extension language support
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

# Extension language support
.if !empty(PKG_OPTIONS:Mperl)
USING_SWIG=	yes
.  include "../../lang/perl5/buildlink3.mk"
PLIST.perl=		yes
USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--enable-perl
.else
CONFIGURE_ARGS+=	--disable-perl
.endif

# Required by some of the other options
.if !empty(USING_SWIG:Myes)
PLIST.swig=		yes
# Tool dependency according to documentation
TOOL_DEPENDS+=		swig>=1.3.29:../../devel/swig
CONFIGURE_ARGS+=	--enable-swig
.else
CONFIGURE_ARGS+=	--disable-swig
.endif
