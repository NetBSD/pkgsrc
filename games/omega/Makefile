# $NetBSD: Makefile,v 1.7 2001/01/07 22:31:46 wiz Exp $

DISTNAME=	omega-0.90-pa4
PKGNAME=	omega-0.90.4
WRKSRC=		${WRKDIR}/omega
CATEGORIES=	games
#MASTER_SITES=	http://dolphin.openprojects.net/Omega/Downloads/Prealphas/
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/proff/

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	http://dolphin.openprojects.net/Omega/
HOMEPAGE=	http://www.win.tue.nl/games/roguelike/omega

USE_CURSES=	yes
REPLACE_NCURSES=	Makefile

ALL_TARGET=

do-install:
	@ ${INSTALL_PROGRAM} -o games -g games -m 4711 ${WRKSRC}/omega \
		 ${PREFIX}/bin/Omega
	@ ${INSTALL_MAN} ${WRKSRC}/docs/omega.6 ${PREFIX}/man/man6
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

.include "../../mk/bsd.prefs.mk"

.if ${NEED_NCURSES} == "YES"
CFLAGS+=	-I${LOCALBASE}/include		# for ncurses.h

post-extract:
	cd ${WRKSRC} &&							\
	for fn in defs.h file.c fixstr.c genclr.c inv.c scr.c; do	\
		${SED} "s/curses.h/ncurses.h/" $$fn > $$fn.new;	\
		${MV} $$fn.new $$fn;				\
	done
.endif

.include "../../mk/bsd.pkg.mk"
