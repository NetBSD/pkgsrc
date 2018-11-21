# $NetBSD: options.mk,v 1.14 2018/11/21 17:12:06 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnuplot
PKG_SUPPORTED_OPTIONS=	cairo cerf gd gnuplot-pdf-doc lua pdf qt4 qt5 wxwidgets x11
PKG_SUGGESTED_OPTIONS=	cairo cerf gd gnuplot-pdf-doc x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gnuplot-pdf-doc qt x11

.if !empty(PKG_OPTIONS:Mcairo)
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-cairo
.endif

.if !empty(PKG_OPTIONS:Mcerf)
.include "../../devel/libcerf/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgd)
.include "../../graphics/gd/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-lua
.endif

# PDF output is also provided by cairo
.if !empty(PKG_OPTIONS:Mpdf)
CONFIGURE_ARGS+=	--with-pdf
.include "../../print/pdflib-lite/buildlink3.mk"
.endif

# to build doc/gnuplot.pdf
.if !empty(PKG_OPTIONS:Mgnuplot-pdf-doc)
PLIST.gnuplot-pdf-doc=	yes
BUILD_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+=	tex-ucs-[0-9]*:../../print/tex-ucs
post-build:
	cd ${WRKSRC}/docs && ${GMAKE} gnuplot.pdf
post-install:
	cd ${WRKSRC}/docs && \
	${INSTALL_DATA} gnuplot.pdf ${DESTDIR}${PREFIX}/share/gnuplot/${API_VERSION}
.endif

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=	yes
.include "../../x11/libXaw/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if !empty(PKG_OPTIONS:Mqt4)
USE_LANGUAGES+=		c++
CONFIGURE_ARGS+=	--with-qt=qt4
PLIST.qt=		yes
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mqt5)
USE_LANGUAGES+=		c++11
CONFIGURE_ARGS+=	--with-qt=qt5
PLIST.qt=		yes
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-qt=no
.endif

.if !empty(PKG_OPTIONS:Mwxwidgets)
USE_LANGUAGES+=		c++
CONFIGURE_ARGS+=	--enable-wxwidgets
.include "../../x11/wxGTK30/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-wxwidgets
.endif
