# $NetBSD: Makefile,v 1.19 2001/12/05 15:00:44 agc Exp $
#

DISTNAME=		battalion
PKGNAME=		battalion-1.4
WRKSRC=			${WRKDIR}/battalionSource
CATEGORIES=		games x11
MASTER_SITES=		http://www.evl.uic.edu/aej/
DISTFILES=		battalionSource1.4.tar.Z battalionSUN4.tar.gz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.evl.uic.edu/aej/AndyBattalion.html
COMMENT=		Virtual reality 3D GL game for X11

NOT_FOR_PLATFORM=	*-*-alpha	# relies on Mesa (gcc)

EXTRACT_ONLY=		battalionSource1.4.tar.Z
USE_X11BASE=		yes
USE_MESA=		yes

do-install:
	${INSTALL} -c -s -o ${ROOT_USER} -g games -m 2755 ${WRKSRC}/battalion ${PREFIX}/bin
	cd ${WRKDIR} && \
	    ${GZCAT} ${DISTDIR}/battalionSUN4.tar.gz | ${GTAR} xmf -
	${INSTALL_DATA_DIR} ${PREFIX}/share/battalion/HELP
	${INSTALL_DATA_DIR} ${PREFIX}/share/battalion/battalion.data/DATA
	${INSTALL_DATA_DIR} ${PREFIX}/share/battalion/battalion.data/MUSIC
	${INSTALL_DATA_DIR} ${PREFIX}/share/battalion/battalion.data/SOUNDS
	${INSTALL_DATA_DIR} ${PREFIX}/share/battalion/battalion.data/TEXTURES
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/DATA/* ${PREFIX}/share/battalion/battalion.data/DATA
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/MUSIC/* ${PREFIX}/share/battalion/battalion.data/MUSIC
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/SOUNDS/* ${PREFIX}/share/battalion/battalion.data/SOUNDS
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/TEXTURES/* ${PREFIX}/share/battalion/battalion.data/TEXTURES
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/battalion.sho ${PREFIX}/share/battalion/battalion.data
	${INSTALL_MAN} ${WRKDIR}/battalionSUN4/battalion.man ${PREFIX}/man/man6/battalion.6
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/HELP/* ${PREFIX}/share/battalion/HELP
	${INSTALL} -o bin -g games -m 664 /dev/null /var/games/battalion_hiscore

pre-clean:
	@${RM} -rf ${WRKDIR}/battalionSUN4

.include "../../mk/bsd.pkg.mk"
