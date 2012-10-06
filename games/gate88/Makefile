# $NetBSD: Makefile,v 1.4 2012/10/06 11:54:39 asau Exp $
#

DISTNAME=	Gate88_Mar19_05
PKGNAME=	gate88-20050319
CATEGORIES=	games
MASTER_SITES=	http://www.queasygames.com/gate88/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.queasygames.com/gate88/
COMMENT=	Deep space intergalactic battle
LICENSE=	gate88-license

RESTRICTED=	${LICENSE}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base x11

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin lib/gate88 lib/gate88/lib lib/gate88/music
INSTALLATION_DIRS+=	lib/gate88/music/non-ingame lib/gate88/sound
INSTALLATION_DIRS+=	share/doc/gate88

do-build:
	sed "s,@PREFIX@,${PREFIX}," files/gate88 > ${WRKSRC}/gate88.sh
	sed "s,@PREFIX@,${PREFIX}," files/gate88server > \
		${WRKSRC}/gate88server.sh
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gate88.sh ${DESTDIR}${PREFIX}/bin/gate88
	${INSTALL_SCRIPT} ${WRKSRC}/gate88server.sh ${DESTDIR}${PREFIX}/bin/gate88server
	${INSTALL_PROGRAM} ${WRKSRC}/gate88 ${DESTDIR}${PREFIX}/lib/gate88
	for i in audio.conf colours.conf debug.conf irc_client.conf \
		irc_connection.conf masterserver.conf multiplayer.conf \
		practice.conf server.conf textcolours.conf video.conf; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/lib/gate88; \
	done
	for i in LGPL_license.txt license.txt readme.txt manual.html; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/share/doc/gate88; \
	done
	${INSTALL_LIB} ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/lib/gate88/lib
	${INSTALL_DATA} ${WRKSRC}/music/*.ogg ${DESTDIR}${PREFIX}/lib/gate88/music
	${INSTALL_DATA} ${WRKSRC}/music/non-ingame/*.ogg \
		${DESTDIR}${PREFIX}/lib/gate88/music/non-ingame
	${INSTALL_DATA} ${WRKSRC}/sound/* ${DESTDIR}${PREFIX}/lib/gate88/sound

.include "../../mk/bsd.pkg.mk"
