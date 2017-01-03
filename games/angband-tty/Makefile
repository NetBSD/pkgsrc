# $NetBSD: Makefile,v 1.40 2017/01/03 21:38:29 roy Exp $
#

DISTNAME=		angband-283
PKGNAME=		angband-tty-2.8.3
PKGREVISION=		6
CATEGORIES=		games
MASTER_SITES=		# ftp://ftp.greyhelm.com/pub/Games/Angband/Angband-2.7.x/Source/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${SPOILERFILE}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.phial.com/angband/
COMMENT=		Tolkien based variant of Moria for tty/console displays

CONFLICTS=		angband-x11-[0-9]*

PKG_DESTDIR_SUPPORT=	destdir

USE_TOOLS+=		gzip pax

WRKSRC=			${WRKDIR}/${DISTNAME}/src
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
MAKE_FILE=		Makefile.std
BUILD_TARGET=		angband

SPOILERFILE=		angband-spoilers.tar.gz

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif

SETGIDGAME=		yes
SPECIAL_PERMS=		bin/angband ${SETGID_GAMES_PERMS}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/angband
	cd ${WRKDIR}/${DISTNAME}/lib && pax -wr * \
		${DESTDIR}${PREFIX}/share/angband
	cd ${DESTDIR}${PREFIX}/share/angband/help && \
		pax -O -zrf ${DISTDIR}/${SPOILERFILE}
	${CHOWN} -R ${GAMEOWN}:${GAMEGRP} ${DESTDIR}${PREFIX}/share/angband
	cd ${DESTDIR}${PREFIX}/share/angband && \
		${CHMOD} ${GAMEDATAMODE} */*
	cd ${DESTDIR}${PREFIX}/share/angband && \
		${CHMOD} ${GAMEDIRMODE} apex bone data edit file help info save user xtra
	${INSTALL_PROGRAM} ${WRKSRC}/angband ${DESTDIR}${PREFIX}/bin

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
