# $NetBSD: Makefile,v 1.6 1999/12/22 05:09:19 sakamoto Exp $
#

DISTNAME=	Rollemup
PKGNAME=	rollemup-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://usa.lostboys.nl/pub/medialab/rollemup/Linux/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.medialab.lostboys.nl/rollemup/

LICENSE=	no-commercial-use
RESTRICTED=	You are not allowed to distribute the software by any means. \
		You are allowed to download a copy from this site for personal use. \
		See http://www.medialab.lostboys.nl/content/showcase/license.html
MIRROR_DISTFILE=no

EXTRACT_ONLY=	# empty
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

MESSAGE_FILE=	${WRKDIR}/MESSAGE

PLIST_SRC=	${WRKDIR}/PLIST.src
GAMES_DIR=	share/games

ONLY_FOR_PLATFORM=	*-*-i386

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS=	suse_linux-6.1p1:../../emulators/suse_linux
.endif

do-build:
	@${SED} -e 's|$${PREFIX}|${PREFIX}|g' \
		-e 's|$${GAMES_DIR}|${GAMES_DIR}|g' \
		${FILESDIR}/rollemup.sh > ${WRKDIR}/rollemup
	@${SED} -e 's|$${PREFIX}|${PREFIX}|g' \
		-e 's|$${GAMES_DIR}|${GAMES_DIR}|g' \
		${PKGDIR}/MESSAGE > ${MESSAGE_FILE}
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
	  find ${GAMES_DIR}/Rollemup -type f >> ${PLIST_SRC}; \
	  for DIR in `find ${GAMES_DIR}/Rollemup -type d | sort -r`; do \
	    ${ECHO} "@dirrm $$DIR" >> ${PLIST_SRC}; \
	  done)
	@${CHOWN} root:games ${PREFIX}/bin/Rollemup
	@${CHMOD} 2755 ${PREFIX}/bin/Rollemup
	@${CHOWN} -R root:games ${PREFIX}/${GAMES_DIR}/Rollemup
	@${CHMOD} 775 ${PREFIX}/${GAMES_DIR}/Rollemup/Games
	@${CHMOD} 775 ${PREFIX}/${GAMES_DIR}/Rollemup/Upload
	@${CHMOD} 664 ${PREFIX}/${GAMES_DIR}/Rollemup/Rollemup.ini

.include "../../mk/bsd.pkg.mk"
