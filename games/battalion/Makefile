# $NetBSD: Makefile,v 1.9 1998/09/30 20:03:18 tron Exp $
#

DISTNAME=	battalion
PKGNAME=	battalion-1.4
WRKSRC=		${WRKDIR}/battalionSource
CATEGORIES=	games x11
MASTER_SITES=	http://www.evl.uic.edu/aej/
DISTFILES=	battalionSource1.4.tar.Z battalionSUN4.tar.gz

NOT_FOR_ARCHS=	alpha	# relies on Mesa (gcc)

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.evl.uic.edu/aej/AndyBattalion.html

DEPENDS+=	Mesa-3.0:../../graphics/Mesa

EXTRACT_ONLY=	battalionSource1.4.tar.Z
USE_X11=	yes

do-install:
	${INSTALL} -c -s -o root -g games -m 2755 ${WRKSRC}/battalion ${PREFIX}/bin
	@${EXTRACT_CMD} -xzmf ${DISTDIR}/battalionSUN4.tar.gz -C ${WRKDIR}
	${MKDIR} ${PREFIX}/share/battalion/HELP
	${MKDIR} ${PREFIX}/share/battalion/battalion.data/DATA
	${MKDIR} ${PREFIX}/share/battalion/battalion.data/MUSIC
	${MKDIR} ${PREFIX}/share/battalion/battalion.data/SOUNDS
	${MKDIR} ${PREFIX}/share/battalion/battalion.data/TEXTURES
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/DATA/* ${PREFIX}/share/battalion/battalion.data/DATA
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/MUSIC/* ${PREFIX}/share/battalion/battalion.data/MUSIC
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/SOUNDS/* ${PREFIX}/share/battalion/battalion.data/SOUNDS
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/TEXTURES/* ${PREFIX}/share/battalion/battalion.data/TEXTURES
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/battalion.data/battalion.sho ${PREFIX}/share/battalion/battalion.data
	${INSTALL_MAN} ${WRKDIR}/battalionSUN4/battalion.man ${PREFIX}/man/man6/battalion.6
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/HELP/* ${PREFIX}/share/battalion/HELP
	@cat /dev/null >>/var/games/battalion_hiscore
	chown bin:games /var/games/battalion_hiscore
	chmod 664 /var/games/battalion_hiscore

pre-clean:
	@${RM} -rf ${WRKDIR}/battalionSUN4

.include "../../mk/bsd.pkg.mk"
