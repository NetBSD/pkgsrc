# $NetBSD: Makefile,v 1.18 2005/08/03 03:19:40 grant Exp $
#

DISTNAME=	libebml-0.7.5
CATEGORIES=	devel
MASTER_SITES=	http://dl.matroska.org/downloads/libebml/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.sourceforge.net/projects/ebml/
COMMENT=	Extensible Binary Meta Language support library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake
USE_LANGUAGES=	c++

NO_CONFIGURE=	yes
MAKEFLAGS+=	prefix=${PREFIX:Q}
MAKE_ENV+=	CXXFLAGS=${CXXFLAGS:Q} RANLIB=${RANLIB:Q}
BUILD_DIRS=	${WRKDIR}/${DISTNAME}/make/linux
BUILD_TARGET=	staticlib
INSTALL_TARGET=	install_headers install_staticlib

ONLY_FOR_COMPILER=	gcc icc

.include "../../mk/bsd.pkg.mk"
