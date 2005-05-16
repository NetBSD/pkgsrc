# $NetBSD: Makefile,v 1.25 2005/05/16 01:15:32 jlam Exp $

DISTNAME=	Rollemup
PKGNAME=	rollemup-1.0
CATEGORIES=	games
MASTER_SITES=	http://savor.gulic.org/demos/
# was http://usa.lostboys.nl/medialab/rollemup/Linux/

MAINTAINER=	sakamoto@NetBSD.org
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

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BIN_ON_CDROM=${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

PLIST_SRC=	${WRKDIR}/PLIST.src
GAMES_DIR=	share/games
MESSAGE_SUBST+=	GAMES_DIR=${GAMES_DIR}

PKGSRC_USE_TOOLS+=	gtar

ONLY_FOR_PLATFORM=	*-*-i386

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS=	suse_compat>=6.1:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS=	suse_x11>=6.1:../../emulators/${SUSE_DIR_PREFIX}_x11
CHECK_SHLIBS=	no
.endif

do-build:
	@${SED} -e 's|$${PREFIX}|${PREFIX}|g' \
		-e 's|$${GAMES_DIR}|${GAMES_DIR}|g' \
		${FILESDIR}/rollemup.sh > ${WRKDIR}/rollemup
	@${SED} -e 's|$${PREFIX}|${PREFIX}|g' ${FILESDIR}/README.Rollemup \
		> ${WRKDIR}/README.Rollemup

do-install:
	@${GTAR} xCzf ${PREFIX}/${GAMES_DIR} ${_DISTDIR}/${DISTFILES}
	@${TOUCH} ${PREFIX}/${GAMES_DIR}/Rollemup/Rollemup.ini
	@${MV} ${PREFIX}/${GAMES_DIR}/Rollemup/Rollemup ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/rollemup ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKDIR}/README.Rollemup \
		${PREFIX}/${GAMES_DIR}/Rollemup
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${PREFIX}; \
	  ${FIND} ${GAMES_DIR}/Rollemup -type f -print >> ${PLIST_SRC}; \
	  for DIR in `${FIND} ${GAMES_DIR}/Rollemup -type d -print | sort -r`; do \
	    ${ECHO} "@dirrm $$DIR" >> ${PLIST_SRC}; \
	  done)
	@${CHOWN} ${ROOT_USER}:games ${PREFIX}/bin/Rollemup
	@${CHMOD} 2755 ${PREFIX}/bin/Rollemup
	@${CHOWN} -R ${ROOT_USER}:games ${PREFIX}/${GAMES_DIR}/Rollemup
	@${CHMOD} 775 ${PREFIX}/${GAMES_DIR}/Rollemup/Games
	@${CHMOD} 775 ${PREFIX}/${GAMES_DIR}/Rollemup/Upload
	@${CHMOD} 664 ${PREFIX}/${GAMES_DIR}/Rollemup/Rollemup.ini

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
