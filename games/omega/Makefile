# $NetBSD: Makefile,v 1.16 2003/09/19 23:08:23 dent Exp $

DISTNAME=	omega-0.90-pa4
PKGNAME=	omega-0.90.4
PKGREVISION=			1
WRKSRC=		${WRKDIR}/omega
CATEGORIES=	games
#MASTER_SITES=	http://dolphin.openprojects.net/Omega/Downloads/Prealphas/
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/proff/

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	http://dolphin.openprojects.net/Omega/
HOMEPAGE=	http://home-13.tiscali-business.nl/~bwaijers/omega/
COMMENT=	Complex rogue-like game of exploration with a sense of humor

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
