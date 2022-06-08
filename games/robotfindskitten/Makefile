# $NetBSD: Makefile,v 1.6 2022/06/08 22:19:51 rillig Exp $
#

DISTNAME=	robotfindskitten-2.7182818.701
CATEGORIES=	games
MASTER_SITES=	http://robotfindskitten.org/download/POSIX/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://robotfindskitten.org/
COMMENT=	Yet another zen simulation
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
AUTO_MKDIRS=	yes
INFO_FILES=	yes
FAKE_NCURSES=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/nki/vanilla.nki ${DESTDIR}${PREFIX}/share/games/robotfindskitten/

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
