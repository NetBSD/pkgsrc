# $NetBSD: Makefile,v 1.1.1.1 1999/10/22 05:39:44 sakamoto Exp $
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
NO_PACKAGE=	yes

PLIST_SRC=	${WRKDIR}/PLIST.src
GAMES_DIR=	share/games

ONLY_FOR_PLATFORM=	*-*-i386

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.if (${MACHINE_ARCH} == "i386")
.if !exists(/emul/linux/lib/ld-linux.so.2)
IGNORE= requires Linux glibc2 libraries - see compat_linux(8)
.endif
.endif
.endif

do-build:
	@${SED} -e 's|$${PREFIX}|${PREFIX}|g' ${FILESDIR}/rollemup.sh \
		> ${WRKDIR}/rollemup
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
	@chown root:games ${PREFIX}/bin/Rollemup
	@chmod 2755 ${PREFIX}/bin/Rollemup
	@chown -R root:games ${PREFIX}/${GAMES_DIR}/Rollemup
	@chmod 775 ${PREFIX}/${GAMES_DIR}/Rollemup/Games
	@chmod 775 ${PREFIX}/${GAMES_DIR}/Rollemup/Upload
	@chmod 664 ${PREFIX}/${GAMES_DIR}/Rollemup/Rollemup.ini

.include "../../mk/bsd.pkg.mk"
