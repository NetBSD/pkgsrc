# $NetBSD: Makefile,v 1.12 2002/09/20 04:48:15 jlam Exp $

DISTNAME=	kdegraphics-2.2.2
PKGREVISION=	1
CATEGORIES=	graphics
COMMENT=	Graphics programs for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde
#DEPENDS+=	gPhoto2
#DEPENDS+=	gpio

USE_BUILDLINK2=		YES
CONFIGURE_ARGS+=	--without-kamera	# requires gPhoto2, gpio

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../graphics/tiff/buildlink2.mk"
.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"
.include "../../mk/ghostscript.mk"

.include "../../mk/bsd.pkg.mk"
