# $NetBSD: Makefile,v 1.24 2004/10/03 00:14:46 tv Exp $

DISTNAME=	omega-0.90.4-src
PKGNAME=	omega-0.90.4
PKGREVISION=			2
CATEGORIES=	games
MASTER_SITES=	http://www.alcyone.com/binaries/omega/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.alcyone.com/max/projects/omega/
COMMENT=	Complex rogue-like game of exploration with a sense of humor

WRKSRC=			${WRKDIR}/omega
USE_BUILDLINK3=		yes
ALL_TARGET=		# empty

.include "../../mk/bsd.prefs.mk"

.if !empty(SETGIDGAME:M[yY][eE][sS])
FILEMODE=	0660
.else
FILEMODE=	0600
.endif

do-install:
	${INSTALL_GAME} ${WRKSRC}/omega ${PREFIX}/bin/Omega
	${INSTALL_MAN} ${WRKSRC}/docs/omega.6 ${PREFIX}/man/man6
	${INSTALL_DATA_DIR} ${PREFIX}/share/omega
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/share/omega
	${RM} ${PREFIX}/share/omega/license.old
	${CHMOD} ${FILEMODE} ${PREFIX}/share/omega/omega.hi
	${CHMOD} ${FILEMODE} ${PREFIX}/share/omega/omega.log
	${CP} ${PREFIX}/share/omega/omega.hi ${PREFIX}/share/omega/omegahi.bak
	${CHOWN} -R ${GAMEOWN}:${GAMEGRP} ${PREFIX}/share/omega

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/omega
	cd ${WRKSRC}; for f in						\
		buglist.txt docs/compile.all docs/readme.1st		\
		docs/omega.txt docs/readme3 docs/readme4;		\
	do								\
		${INSTALL_DATA} $${f} ${PREFIX}/share/doc/omega;	\
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
