# $NetBSD: Makefile,v 1.30 2008/03/04 06:59:05 jlam Exp $

DISTNAME=	omega-0.90.4-src
PKGNAME=	omega-0.90.4
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.alcyone.com/binaries/omega/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alcyone.com/max/projects/omega/
COMMENT=	Complex rogue-like game of exploration with a sense of humor

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/omega
BUILD_TARGET=		# empty

.include "../../mk/bsd.prefs.mk"

SETGIDGAME=		yes
SPECIAL_PERMS=		bin/Omega ${SETGID_GAMES_PERMS}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omega ${DESTDIR}${PREFIX}/bin/Omega
	${INSTALL_MAN} ${WRKSRC}/docs/omega.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/omega
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/share/omega
	${RM} ${DESTDIR}${PREFIX}/share/omega/license.old
	${CHMOD} 0660 ${DESTDIR}${PREFIX}/share/omega/omega.hi
	${CHMOD} 0660 ${DESTDIR}${PREFIX}/share/omega/omega.log
	${CP} ${PREFIX}/share/omega/omega.hi \
		${DESTDIR}${PREFIX}/share/omega/omegahi.bak

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/omega
	cd ${WRKSRC}; for f in						\
		buglist.txt docs/compile.all docs/readme.1st		\
		docs/omega.txt docs/readme3 docs/readme4;		\
	do								\
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/share/doc/omega; \
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
