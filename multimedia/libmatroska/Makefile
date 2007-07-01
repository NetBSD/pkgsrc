# $NetBSD: Makefile,v 1.21 2007/07/01 20:23:19 heinz Exp $
#

DISTNAME=	libmatroska-0.8.0
PKGREVISION=	1
CATEGORIES=	multimedia devel
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.matroska.org/
COMMENT=	Extensible open standard Audio/Video container format

PKG_DESTDIR_SUPPORT=	user-destdir
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
