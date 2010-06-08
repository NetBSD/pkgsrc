# $NetBSD: Makefile,v 1.1.1.1 2010/06/08 08:45:38 wiz Exp $
#

DISTNAME=	powder114_src
PKGNAME=	${DISTNAME:S/_src//:S/powder/powder-/}
CATEGORIES=	games
MASTER_SITES=	http://www.zincland.com/powder/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zincland.com/powder/index.php?pagename=about
COMMENT=	Multiplatform roguelike game with graphics
LICENSE=	powder-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash gmake

INSTALLATION_DIRS=	bin share/doc/powder

do-build:
	cd ${WRKSRC} && ${TOOLS_PATH.bash} buildall.sh

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
