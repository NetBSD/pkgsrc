# $NetBSD: Makefile,v 1.38 2008/01/19 09:16:20 wiz Exp $

DISTNAME=		battalion
PKGNAME=		battalion-1.4
PKGREVISION=		5
CATEGORIES=		games x11
MASTER_SITES=		http://www.evl.uic.edu/aej/BATTALION/
DISTFILES=		battalionSource1.4.tar.Z battalionSUN4.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.evl.uic.edu/aej/AndyBattalion.html
COMMENT=		Virtual reality 3D GL game for X11

NOT_FOR_PLATFORM=	*-*-alpha	# relies on Mesa (gcc)

WRKSRC=			${WRKDIR}/battalionSource
EXTRACT_ONLY=		battalionSource1.4.tar.Z
USE_TOOLS+=		gtar

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly"
MAKE_ENV+=	LIBFLAGS=-lcompat
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

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
	${INSTALL_MAN} ${WRKDIR}/battalionSUN4/battalion.man ${PREFIX}/${PKGMANDIR}/man6/battalion.6
	${INSTALL_DATA} ${WRKDIR}/battalionSUN4/HELP/* ${PREFIX}/share/battalion/HELP
	${INSTALL} -o bin -g games -m 664 /dev/null /var/games/battalion_hiscore

pre-clean:
	@${RM} -rf ${WRKDIR}/battalionSUN4

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
