# $NetBSD: Makefile,v 1.5 2005/06/16 06:57:54 jlam Exp $

DISTNAME=	cube_2004_05_22
PKGNAME=	cube-20040522
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cube/}

MAINTAINER=	peter@pointless.nl
HOMEPAGE=	http://wouter.fov120.com/cube/
COMMENT=	Cube is a 3D First Person Shooter that uses OpenGL and SDL

BUILD_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

WRKSRC=		${WRKDIR}/cube
CUBE_SRC=	${WRKSRC}/source/src
CUBE_DATA=	${PREFIX}/share/cube

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

post-extract:
	@unzip -q -a -o ${WRKSRC}/source/${DISTNAME}_src.zip -d ${WRKSRC}/source/

post-patch:
	@${ECHO} '#define DATADIR "${CUBE_DATA}"' >> ${CUBE_SRC}/cube.h

do-build:
	@cd ${WRKSRC}/source/enet && ${SH} configure
	@cd ${CUBE_SRC} && ${GMAKE} all

pre-install:
	@${INSTALL_DATA_DIR} ${CUBE_DATA}/savegames

do-install:
	${INSTALL_PROGRAM} ${CUBE_SRC}/cube_client ${PREFIX}/bin
	${INSTALL_PROGRAM} ${CUBE_SRC}/cube_server ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/autoexec.cfg ${CUBE_DATA}
	${CP} -Rp ${WRKSRC}/data ${CUBE_DATA}
	${CP} -Rp ${WRKSRC}/packages ${CUBE_DATA}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
