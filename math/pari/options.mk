# $NetBSD: options.mk,v 1.5 2010/10/01 20:50:55 minskim Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pari
PKG_SUPPORTED_OPTIONS=	doc gmp x11
PKG_SUGGESTED_OPTIONS=	doc gmp x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc
.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=		tex-amsfonts>=3.0:../../fonts/tex-amsfonts
BUILD_DEPENDS+=		tex-pdftex>=1.40.11:../../print/tex-pdftex
PLIST.doc=		yes
BUILD_TARGET+=		doc
INSTALL_TARGET+=	install-doc
MAKE_ENV+=		PDFTEX=${LOCALBASE:Q}/bin/pdftex
.endif

PLIST_VARS+=		nogmp gmp
.if !empty(PKG_OPTIONS:Mgmp)
PLIST.gmp=		yes
CONFIGURE_ARGS+=	--with-gmp=${PREFIX:Q}
.include "../../devel/gmp/buildlink3.mk"
.else
PLIST.nogmp=		yes
.endif

.if !empty(PKG_OPTIONS:Mx11)
USE_TOOLS+=		imake
CONFIGURE_ARGS+=	--graphic=X11
CONFIGURE_ARGS+=	--with-fltk=${PREFIX:Q}
CONFIGURE_ENV+=		X11BASE=${X11BASE:Q}
CONFIGURE_ENV+=		Xincroot=${X11BASE}/include
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--graphic=none
# don't let the configure script find an installed fltk
CONFIGURE_ARGS+=	--with-fltk={BUILDLINK_DIR:Q}/nonexistent
.endif
