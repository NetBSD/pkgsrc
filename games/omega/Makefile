# $NetBSD: Makefile,v 1.20 2004/01/20 12:15:41 agc Exp $

DISTNAME=	omega-0.90.4-src
PKGNAME=	omega-0.90.4
PKGREVISION=			1
CATEGORIES=	games
MASTER_SITES=	http://www.alcyone.com/binaries/omega/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.alcyone.com/max/projects/omega/
COMMENT=	Complex rogue-like game of exploration with a sense of humor

WRKSRC=			${WRKDIR}/omega
USE_BUILDLINK2=		# defined
ALL_TARGET=		# empty

do-install:
	${INSTALL_PROGRAM} -o games -g games -m 4711 ${WRKSRC}/omega	\
		 ${PREFIX}/bin/Omega
	${INSTALL_MAN} ${WRKSRC}/docs/omega.6 ${PREFIX}/man/man6
	${INSTALL_DATA_DIR} ${PREFIX}/share/omega
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/share/omega
	${RM} ${PREFIX}/share/omega/license.old
	${CHMOD} 0600 ${PREFIX}/share/omega/omega.hi
	${CHMOD} 0600 ${PREFIX}/share/omega/omega.log
	${CP} ${PREFIX}/share/omega/omega.hi ${PREFIX}/share/omega/omegahi.bak
	${CHOWN} -R games:games ${PREFIX}/share/omega

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/omega
	cd ${WRKSRC}; for file in					\
		buglist.txt docs/compile.all docs/readme.1st		\
		docs/omega.txt docs/readme3 docs/readme4;		\
	do								\
		${INSTALL_DATA} $${file} ${PREFIX}/share/doc/omega;	\
	done

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
