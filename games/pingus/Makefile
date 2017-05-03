# $NetBSD: Makefile,v 1.24 2017/05/03 08:38:42 jperkin Exp $

DISTNAME=	pingus-0.7.3
PKGREVISION=	17
CATEGORIES=	games
MASTER_SITES=	http://pingus.seul.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pingus.seul.org/
COMMENT=	Lemmings(TM) Clone

BUILD_DEPENDS+=		scons>=0.96:../../devel/scons
USE_LANGUAGES=		c c++11

MAKE_JOBS?=	1

do-configure:
	cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${MAKE_ENV} scons configure CXX=${CXX:Q} CPPPATH=${PREFIX}/include LIBPATH=${PREFIX}/lib

do-build:
	cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${MAKE_ENV} scons ${_MAKE_JOBS}

do-install:
	cd ${WRKSRC} && ./install.sh ${DESTDIR}${PREFIX}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
