# $NetBSD: Makefile,v 1.31 2019/01/02 19:16:20 tnn Exp $

DISTNAME=	pingus-0.7.3
PKGREVISION=	22
CATEGORIES=	games
MASTER_SITES=	https://pingus.seul.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pingus.seul.org/
COMMENT=	Lemmings(TM) Clone

USE_LANGUAGES=		c c++11

do-configure:
	cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${MAKE_ENV} ${SCONSBIN} configure CXX=${CXX:Q} CPPPATH=${PREFIX}/include LIBPATH=${PREFIX}/lib

do-build:
	cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${MAKE_ENV} ${SCONSBIN} -j${MAKE_JOBS:U1}

do-install:
	cd ${WRKSRC} && ./install.sh ${DESTDIR}${PREFIX}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY?=	yes
.include "../../devel/scons/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
