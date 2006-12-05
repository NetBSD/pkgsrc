# $NetBSD: Makefile,v 1.67.4.1 2006/12/05 07:37:42 ghen Exp $

DISTNAME=	kdegraphics-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	graphics
COMMENT=	Graphics programs for the KDE integrated X11 desktop

PATCH_SITES=	ftp://ftp.kde.org/pub/kde/security_patches/
PATCHFILES=	post-3.5.5-kdegraphics.diff

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gs:run pkg-config

BUILDLINK_API_DEPENDS.lcms+=	lcms>=1.12

REPLACE_PERL+=	kghostview/update-to-xt-names.pl

CONFIGURE_ARGS+=	--with-imlib-config=${X11PREFIX}/bin

SUBST_CLASSES+=		kpdf
SUBST_STAGE.kpdf=	post-patch
SUBST_MESSAGE.kpdf=	Fixing hardcoded paths.
SUBST_FILES.kpdf=	kpdf/xpdf/xpdf/GlobalParams.cc
SUBST_SED.kpdf=		-e 's:/usr/pkg:${LOCALBASE}:g'
SUBST_SED.kpdf+=	-e 's:/usr/X11R6:${X11BASE}:g'

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/poppler-qt/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
