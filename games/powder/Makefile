# $NetBSD: Makefile,v 1.6 2012/10/06 11:54:50 asau Exp $
#

DISTNAME=	powder117_src
PKGNAME=	${DISTNAME:S/_src//:S/powder/powder-/}
CATEGORIES=	games
MASTER_SITES=	http://www.zincland.com/powder/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zincland.com/powder/index.php?pagename=about
COMMENT=	Multiplatform roguelike game with graphics
LICENSE=	powder-license

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash gmake

INSTALLATION_DIRS=	bin share/doc/powder

REPLACE_BASH=	buildall.sh gfx/rebuild.sh rooms/buildrooms.bash

do-build:
	cd ${WRKSRC} && ./buildall.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/powder ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/CREDITS.TXT \
		${DESTDIR}${PREFIX}/share/doc/powder
	${INSTALL_DATA} ${WRKSRC}/LICENSE.TXT \
		${DESTDIR}${PREFIX}/share/doc/powder
	${INSTALL_DATA} ${WRKSRC}/README.TXT \
		${DESTDIR}${PREFIX}/share/doc/powder

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
