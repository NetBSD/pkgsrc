# $NetBSD: Makefile,v 1.3 2000/01/02 03:28:54 wiz Exp $
# FreeBSD Id: ports/games/omega/Makefile,v 1.3 1999/08/25 06:04:09 obrien Exp

DISTNAME=	omega-0.90-pa4
PKGNAME=	omega-0.90.4
WRKSRC=		${WRKDIR}/omega
CATEGORIES=	games
#MASTER_SITES=	http://dolphin.openprojects.net/Omega/Downloads/Prealphas/
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/proff/

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	http://dolphin.openprojects.net/Omega/
HOMEPAGE=	http://www.win.tue.nl/games/roguelike/omega

DEPENDS+=	ncurses-4.2:../../devel/ncurses

ALL_TARGET=

#ncurses
CFLAGS+=	-I${PREFIX}/include

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/omega ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/docs/omega.6 ${PREFIX}/man/man6
	@ ${CHOWN} games.games ${PREFIX}/bin/omega
	@ ${CHMOD} 4711 ${PREFIX}/bin/omega
	@ ${MKDIR} ${PREFIX}/share/omega
	@ ${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/share/omega
	@ ${RM} ${PREFIX}/share/omega/license.old
	@ ${CHMOD} 0600 ${PREFIX}/share/omega/omega.hi
	@ ${CHMOD} 0600 ${PREFIX}/share/omega/omega.log
	@ ${CP} ${PREFIX}/share/omega/omega.hi ${PREFIX}/share/omega/omegahi.bak
	@ ${CHOWN} -R games:games ${PREFIX}/share/omega

post-install:
	@ ${MKDIR} ${PREFIX}/share/doc/omega
.for file in buglist.txt docs/compile.all docs/readme.1st docs/omega.txt docs/readme3 docs/readme4
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/omega
.endfor

.include "../../mk/bsd.pkg.mk"
