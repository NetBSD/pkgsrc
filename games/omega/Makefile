# $NetBSD: Makefile,v 1.11 2001/12/25 21:21:39 wiz Exp $

DISTNAME=	omega-0.90-pa4
PKGNAME=	omega-0.90.4
WRKSRC=		${WRKDIR}/omega
CATEGORIES=	games
#MASTER_SITES=	http://dolphin.openprojects.net/Omega/Downloads/Prealphas/
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/proff/

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	http://dolphin.openprojects.net/Omega/
HOMEPAGE=	http://www.win.tue.nl/games/roguelike/omega
COMMENT=	Complex rogue-like game of exploration with a sense of humor

USE_BUILDLINK_ONLY=	# defined
ALL_TARGET=		# empty

# Change references from <curses.h> to <ncurses.h> in the source files.
post-extract:
	cd ${WRKSRC}; for file in *.[ch]; do				\
		${SED} -e "s|<curses\.h>|<ncurses.h>|g"			\
			$${file} > $${file}.presubst;			\
		${MV} -f $${file}.presubst $${file};			\
	done

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

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
