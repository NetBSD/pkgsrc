# $NetBSD: Makefile,v 1.30 2004/02/09 14:01:22 seb Exp $

DISTNAME=	kdegraphics-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	graphics
COMMENT=	Graphics programs for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

#DEPENDS+=	gPhoto2
#DEPENDS+=	gpio

USE_BUILDLINK2=		YES

BUILDLINK_DEPENDS.lcms=	lcms>=1.12

CONFIGURE_ARGS+=	--without-kamera	# requires gPhoto2, gpio
CONFIGURE_ARGS+=	--with-imlib-config=${X11PREFIX}/bin

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../converters/fribidi/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../graphics/sane-backends/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
