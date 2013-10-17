# $NetBSD: Makefile,v 1.35 2013/10/17 16:19:41 roy Exp $

DISTNAME=	omega-0.90.4-src
PKGNAME=	omega-0.90.4
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.alcyone.com/binaries/omega/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alcyone.com/max/projects/omega/
COMMENT=	Complex rogue-like game of exploration with a sense of humor

SETGIDGAME=		yes

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/omega
BUILD_TARGET=		# empty

.include "../../mk/bsd.prefs.mk"

SPECIAL_PERMS=		bin/Omega ${SETGID_GAMES_PERMS}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6 share/omega share/doc/omega

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omega ${DESTDIR}${PREFIX}/bin/Omega
	${INSTALL_MAN} ${WRKSRC}/docs/omega.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/share/omega
	${RM} ${DESTDIR}${PREFIX}/share/omega/license.old
	${CHMOD} 0660 ${DESTDIR}${PREFIX}/share/omega/omega.hi
	${CHMOD} 0660 ${DESTDIR}${PREFIX}/share/omega/omega.log
	${CP} ${DESTDIR}${PREFIX}/share/omega/omega.hi \
		${DESTDIR}${PREFIX}/share/omega/omegahi.bak
	cd ${WRKSRC}; for f in						\
		buglist.txt docs/compile.all docs/readme.1st		\
		docs/omega.txt docs/readme3 docs/readme4;		\
	do								\
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/share/doc/omega; \
	done

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
