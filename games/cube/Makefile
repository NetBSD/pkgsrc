# $NetBSD: Makefile,v 1.9 2006/05/21 21:32:22 rillig Exp $

DISTNAME=	cube_2004_05_22
PKGNAME=	cube-20040522
PKGREVISION=	4
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cube/}

MAINTAINER=	peter@pointless.nl
HOMEPAGE=	http://wouter.fov120.com/cube/
COMMENT=	Cube is a 3D First Person Shooter that uses OpenGL and SDL

BUILD_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

WRKSRC=		${WRKDIR}/cube
CUBE_SRC_DIR=	${WRKSRC}/source/src
CUBE_DATA_DIR=	${PREFIX}/share/cube

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake unzip

INSTALLATION_DIRS=	bin

post-extract:
	${UNZIP_CMD} -q -a -o ${WRKSRC}/source/${DISTNAME}_src.zip -d ${WRKSRC}/source/

post-patch:
	@${ECHO} '#define DATADIR "${CUBE_DATA_DIR}"' >> ${CUBE_SRC_DIR}/cube.h

do-build:
	cd ${WRKSRC}/source/enet && ${SH} configure
	cd ${CUBE_SRC_DIR} && ${GMAKE} all

pre-install:
	${INSTALL_DATA_DIR} ${CUBE_DATA_DIR}/savegames

do-install:
	${INSTALL_PROGRAM} ${CUBE_SRC_DIR}/cube_client ${PREFIX}/bin
	${INSTALL_PROGRAM} ${CUBE_SRC_DIR}/cube_server ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/autoexec.cfg ${CUBE_DATA_DIR}
	${CP} -Rp ${WRKSRC}/data ${CUBE_DATA_DIR}
	${CP} -Rp ${WRKSRC}/packages ${CUBE_DATA_DIR}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
