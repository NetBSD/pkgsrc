# $NetBSD: Makefile,v 1.40 2010/02/07 17:32:40 heinz Exp $

DISTNAME=	Rollemup
PKGNAME=	rollemup-1.0
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://ftp.giga.or.at/pub/lost-distfiles/ \
		ftp://ftp.tw.freebsd.org/pub/ports/distfiles/ \
		http://www.uberstudent.org/archive/programs/games/
# was http://usa.lostboys.nl/medialab/rollemup/Linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.medialab.lostboys.nl/projects/madewith/pinball/pinballgame.html
COMMENT=	Multi Ball, Player, Platform, Media, Cool Pinball game
LICENSE=	no-commercial-use

RESTRICTED=	You are not allowed to distribute the software by any means. \
		You are allowed to download a copy from this site for personal use. \
		See http://www.medialab.lostboys.nl/content/showcase/license.html
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PKG_DESTDIR_SUPPORT=	destdir

USE_TOOLS+=		gtar

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	compat x11

PLIST_SRC=		${WRKDIR}/PLIST.src
GAMES_DIR=		share/games
MESSAGE_SUBST+=		GAMES_DIR=${GAMES_DIR}

SETGIDGAME=		yes
CONF_FILES_PERMS+=	/dev/null ${GAMES_DIR}/Rollemup/Rollemup.ini	\
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
SPECIAL_PERMS=		bin/Rollemup ${SETGID_GAMES_PERMS}

INSTALLATION_DIRS=	bin

do-build:
	${SED} -e 's|$${PREFIX}|${PREFIX}|g' \
		-e 's|$${GAMES_DIR}|${GAMES_DIR}|g' \
		${FILESDIR}/rollemup.sh > ${WRKDIR}/rollemup
	${SED} -e 's|$${PREFIX}|${PREFIX}|g' ${FILESDIR}/README.Rollemup \
		> ${WRKDIR}/README.Rollemup

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/${GAMES_DIR}
	${GTAR} xCzf ${DESTDIR}${PREFIX}/${GAMES_DIR} ${_DISTDIR}/${DISTFILES}
	${TOUCH} ${DESTDIR}${PREFIX}/${GAMES_DIR}/Rollemup/Rollemup.ini
	${MV} ${PREFIX}/${GAMES_DIR}/Rollemup/Rollemup ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/rollemup ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/README.Rollemup \
		${DESTDIR}${PREFIX}/${GAMES_DIR}/Rollemup
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	${CHOWN} -R ${ROOT_USER}:${GAMEGRP} \
		${DESTDIR}${PREFIX}/${GAMES_DIR}/Rollemup
	${CHMOD} ${GAMEDIRMODE} ${DESTDIR}${PREFIX}/${GAMES_DIR}/Rollemup/Games
	${CHMOD} ${GAMEDIRMODE} ${DESTDIR}${PREFIX}/${GAMES_DIR}/Rollemup/Upload

.include "../../mk/bsd.pkg.mk"
