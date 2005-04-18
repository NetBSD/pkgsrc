# $NetBSD: Makefile,v 1.12 2005/04/18 00:57:21 salo Exp $
#

DISTNAME=	libmatroska-0.7.6
CATEGORIES=	multimedia devel
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.matroska.org/
COMMENT=	Extensible open standard Audio/Video container format

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c++

NO_CONFIGURE=	yes
MAKEFLAGS+=	prefix=${PREFIX:Q}
MAKE_ENV+=	CXXFLAGS=${CXXFLAGS:Q} RANLIB=${RANLIB:Q}
BUILD_DIRS=	${WRKDIR}/${DISTNAME}/make/linux
BUILD_TARGET=	staticlib
INSTALL_TARGET=	install_headers install_staticlib
TEST_TARGET=	test

ONLY_FOR_COMPILER=	gcc

.include "../../devel/libebml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
