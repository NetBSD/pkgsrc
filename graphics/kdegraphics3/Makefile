# $NetBSD: Makefile,v 1.11 2003/01/02 09:12:25 skrll Exp $

DISTNAME=	kdegraphics-3.0.5a
CATEGORIES=	graphics
COMMENT=	Graphics programs for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

#DEPENDS+=	gPhoto2
#DEPENDS+=	gpio

USE_BUILDLINK2=		YES

CONFIGURE_ARGS+=	--without-kamera	# requires gPhoto2, gpio

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

#.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
