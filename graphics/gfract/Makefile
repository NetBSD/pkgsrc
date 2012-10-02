# $NetBSD: Makefile,v 1.46 2012/10/02 17:11:10 tron Exp $
#

DISTNAME=		gfract-0.32
PKGREVISION=		14
CATEGORIES=		graphics x11
MASTER_SITES=		http://www.oskusoft.com/osku/gfract/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} gfract-palettes-0.1.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.oskusoft.com/osku/gfract/index.html
COMMENT=		Gtk-based fractal program

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake pkg-config
BUILD_TARGET=		gfract

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing prefix.
SUBST_STAGE.prefix=	post-extract
SUBST_FILES.prefix=	main.cpp
SUBST_SED.prefix=	-e "s,/usr/local,${PREFIX},g"

INSTALLATION_DIRS=	bin

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-extract:
	${MV} ${WRKDIR}/monk2\'.map ${WRKDIR}/monk2.map

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/gfract
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/gfract/palettes
	${INSTALL_DATA} ${WRKDIR}/*.map \
		${DESTDIR}${PREFIX}/share/gfract/palettes/
	${INSTALL_DATA} ${WRKSRC}/gfract.xpm ${DESTDIR}${PREFIX}/share/gfract/
	${INSTALL_PROGRAM} ${WRKSRC}/gfract ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
