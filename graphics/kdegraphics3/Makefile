# $NetBSD: Makefile,v 1.123 2014/02/12 23:18:01 tron Exp $

DISTNAME=	kdegraphics-${_KDE_VERSION}
PKGREVISION=	38
CATEGORIES=	graphics
COMMENT=	Graphics programs for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_TOOLS+=		gs:run pkg-config

DEPENDS+=	urw-fonts-[0-9]*:../../fonts/urw-fonts
BUILDLINK_API_DEPENDS.lcms+=	lcms>=1.12

REPLACE_PERL+=	kghostview/update-to-xt-names.pl

CONFIGURE_ARGS+=	--with-imlib-config=${X11PREFIX}/bin

FRIBIDI_LIBS=	${TOOLS_PATH.pkg-config} --libs fribidi
FRIBIDI_CFLAGS=	${TOOLS_PATH.pkg-config} --cflags fribidi

CONFIGURE_ARGS+=	FRIBIDI_LIBS=${FRIBIDI_LIBS:sh:Q}
CONFIGURE_ARGS+=	FRIBIDI_CFLAGS=${FRIBIDI_CFLAGS:sh:Q}

SUBST_CLASSES+=		kpdf
SUBST_STAGE.kpdf=	post-patch
SUBST_MESSAGE.kpdf=	Fixing hardcoded paths.
SUBST_FILES.kpdf=	kpdf/xpdf/xpdf/GlobalParams.cc
SUBST_SED.kpdf=		-e 's:/usr/pkg:${LOCALBASE}:g'
SUBST_SED.kpdf+=	-e 's:/usr/X11R6:${X11BASE}:g'

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
# OpenEXR uses exceptions in the header files
BUILDLINK_TRANSFORM+=	rm:-fno-exceptions
.endif

.include "../../meta-pkgs/kde3/kde3.mk"
.if ${OPSYS} == "Linux"
.include "../../graphics/libv4l/buildlink3.mk"
.endif
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
