# $NetBSD: Makefile,v 1.19 2004/12/14 20:36:54 minskim Exp $
#

DISTNAME=		gfract-0.30
CATEGORIES=		graphics x11
MASTER_SITES=		http://www.cs.Helsinki.FI/u/salerma/gfract/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} gfract-palettes-0.1.tar.gz

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.cs.Helsinki.FI/u/salerma/gfract/
COMMENT=		Gtk-based fractal program

USE_BUILDLINK3=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
BUILD_TARGET=		gfract

PKG_INSTALLATION_TYPES=	overwrite pkgviews

SUBST_CLASSES=		prefix
SUBST_MESSAGE.prefix=	"Fixing prefix."
SUBST_STAGE.prefix=	post-extract
SUBST_FILES.prefix=	main.cpp
SUBST_SED.prefix=	-e "s,/usr/local,${PREFIX},g"

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-extract:
	${MV} ${WRKDIR}/monk2\'.map ${WRKDIR}/monk2.map

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gfract
	${INSTALL_DATA_DIR} ${PREFIX}/share/gfract/palettes
	${INSTALL_DATA} ${WRKDIR}/*.map ${PREFIX}/share/gfract/palettes/
	${INSTALL_DATA} ${WRKSRC}/gfract.xpm ${PREFIX}/share/gfract/
	${INSTALL_PROGRAM} ${WRKSRC}/gfract ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
