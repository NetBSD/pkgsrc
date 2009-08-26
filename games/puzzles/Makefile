# $NetBSD: Makefile,v 1.5 2009/08/26 19:57:33 sno Exp $
#

DISTNAME=	puzzles-r8605
PKGNAME=	${DISTNAME:S/-r/-/}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.chiark.greenend.org.uk/~sgtatham/puzzles/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.chiark.greenend.org.uk/~sgtatham/puzzles/
COMMENT=	Collection of small one-player puzzle games by Simon Tatham
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin share/doc/puzzles

DIST_SUBDIR=	puzzles-20090803
USE_TOOLS+=	gmake pkg-config

BUILDLINK_TRANSFORM+=	rm:-Werror
MAKE_FLAGS=	prefix=${PREFIX}
MAKE_FLAGS=	gamesdir=${PREFIX}/bin

post-install:
	${INSTALL_DATA} ${WRKSRC}/puzzles.txt \
		${DESTDIR}${PREFIX}/share/doc/puzzles

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
