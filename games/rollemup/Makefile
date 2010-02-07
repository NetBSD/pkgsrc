# $NetBSD: Makefile,v 1.41 2010/02/07 20:59:14 heinz Exp $

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

PKG_DESTDIR_SUPPORT=	user-destdir

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	compat x11

PLIST_SRC=		${WRKDIR}/PLIST.src
EG_DIR=			share/examples/Rollemup
GAMES_DIR=		share/games
MESSAGE_SUBST+=		GAMES_DIR=${GAMES_DIR}

SETGIDGAME=		yes

SPECIAL_PERMS=		bin/Rollemup ${SETGID_GAMES_PERMS}

CONF_FILES_PERMS=	${EG_DIR}/Rollemup.ini				\
			${GAMES_DIR}/Rollemup/Rollemup.ini		\
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
CONF_FILES_PERMS+=	${EG_DIR}/Highscore.html			\
			${GAMES_DIR}/Rollemup/Upload/Highscore.html	\
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
OWN_DIRS_PERMS+=	${GAMES_DIR}/Rollemup/Games ${GAMES_USER}	\
			${GAMES_GROUP} ${GAMEDIRMODE}
OWN_DIRS_PERMS+=	${GAMES_DIR}/Rollemup/Upload ${GAMES_USER}	\
			${GAMES_GROUP} ${GAMEDIRMODE}

INSTALLATION_DIRS=	bin ${EG_DIR} ${GAMES_DIR}

do-extract:
	@mkdir ${WRKSRC} # dummy directory

do-build:
	${SED} -e 's|$${PREFIX}|${PREFIX}|g' \
		-e 's|$${GAMES_DIR}|${GAMES_DIR}|g' \
		${FILESDIR}/rollemup.sh > ${WRKDIR}/rollemup
	${SED} -e 's|$${PREFIX}|${PREFIX}|g' ${FILESDIR}/README.Rollemup \
		> ${WRKDIR}/README.Rollemup

do-install:
	${EXTRACTOR} -d ${DESTDIR}${PREFIX}/${GAMES_DIR} ${DISTDIR}/${DISTFILES}
	${TOUCH} ${DESTDIR}${PREFIX}/${EG_DIR}/Rollemup.ini
	${MV} ${DESTDIR}${PREFIX}/${GAMES_DIR}/Rollemup/Upload/Highscore.html \
		${DESTDIR}${PREFIX}/${EG_DIR}
	${MV} ${DESTDIR}${PREFIX}/${GAMES_DIR}/Rollemup/Rollemup \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/rollemup ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/README.Rollemup \
		${DESTDIR}${PREFIX}/${GAMES_DIR}/Rollemup
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
