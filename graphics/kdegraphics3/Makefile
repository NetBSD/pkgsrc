# $NetBSD: Makefile,v 1.4 2002/08/28 07:15:28 skrll Exp $

DISTNAME=	kdegraphics-3.0.3
CATEGORIES=	graphics
COMMENT=	Graphics programs for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

DEPENDS+=	ghostscript>=6.01:../../print/ghostscript
#DEPENDS+=	gPhoto2
#DEPENDS+=	gpio

USE_BUILDLINK_ONLY=	YES

CONFIGURE_ARGS+=	--without-kamera	# requires gPhoto2, gpio

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS=			-Wl,--export-dynamic
.endif

#.include "../../graphics/tiff/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../x11/kde3/buildlink.mk"
.include "../../x11/kdebase3/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
