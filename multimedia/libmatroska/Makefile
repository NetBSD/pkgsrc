# $NetBSD: Makefile,v 1.18 2005/12/05 20:50:43 rillig Exp $
#

DISTNAME=	libmatroska-0.7.7
CATEGORIES=	multimedia devel
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.matroska.org/
COMMENT=	Extensible open standard Audio/Video container format

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake
USE_LANGUAGES=	c++

NO_CONFIGURE=	yes
MAKEFLAGS+=	prefix=${PREFIX:Q}
MAKE_ENV+=	CXXFLAGS=${CXXFLAGS:M*:Q} RANLIB=${RANLIB:Q}
BUILD_DIRS=	make/linux
BUILD_TARGET=	staticlib
INSTALL_TARGET=	install_headers install_staticlib
TEST_TARGET=	test

.include "../../devel/libebml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
