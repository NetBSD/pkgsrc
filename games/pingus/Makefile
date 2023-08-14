# $NetBSD: Makefile,v 1.46 2023/08/14 05:24:27 wiz Exp $

DISTNAME=	pingus-0.7.6
PKGREVISION=	13
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Pingus/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://pingus.seul.org/
COMMENT=	Lemmings(TM) Clone
LICENSE=	gnu-gpl-v3

MAKE_ENV+=	FIND=${TOOLS_CMD.find:Q} MKDIR=${TOOLS_CMD.mkdir:Q}
MAKE_ENV+=	RM=${TOOLS_CMD.rm:Q} SCONSBIN=${SCONSBIN:Q}
USE_LANGUAGES=	c c++11
USE_TOOLS=	pkg-config

DATADIR=	${PREFIX}/share/pingus

SUBST_CLASSES+=		data
SUBST_MESSAGE.data=	Set default --datadir for pingus executable to ${DATADIR}
SUBST_STAGE.data=	pre-configure
SUBST_FILES.data=	src/pingus/pingus_main.cpp
SUBST_VARS.data=	DATADIR

SCONS_DO_INSTALL=	no
do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${MAKE} install

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=	yes
.include "../../devel/scons4/build.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
