# $NetBSD: Makefile,v 1.7 2002/10/02 12:06:41 markd Exp $

DISTNAME=	kdegraphics-3.0.3
CATEGORIES=	graphics
COMMENT=	Graphics programs for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

#DEPENDS+=	gPhoto2
#DEPENDS+=	gpio

USE_BUILDLINK2=		YES

CONFIGURE_ARGS+=	--without-kamera	# requires gPhoto2, gpio

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

#.include "../../graphics/tiff/buildlink.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
