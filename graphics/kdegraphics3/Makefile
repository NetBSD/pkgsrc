# $NetBSD: Makefile,v 1.25 2003/09/17 23:45:22 markd Exp $

DISTNAME=	kdegraphics-3.1.4
CATEGORIES=	graphics
COMMENT=	Graphics programs for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

#DEPENDS+=	gPhoto2
#DEPENDS+=	gpio

USE_BUILDLINK2=		YES

CONFIGURE_ARGS+=	--without-kamera	# requires gPhoto2, gpio
CONFIGURE_ARGS+=	--with-imlib-config=${X11PREFIX}/bin

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

FOO_MAIN_FILES= \
	kview/kview_main.cpp \
	kuickshow/src/kuickshow_main.cpp

.include "../../meta-pkgs/kde3/Makefile.foo_main"

.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../graphics/sane-backends/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
