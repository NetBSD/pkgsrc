# $NetBSD: Makefile,v 1.16 2005/05/22 20:07:52 jlam Exp $
#

DISTNAME=	libebml-0.7.4
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

ONLY_FOR_COMPILER=	gcc

.include "../../mk/bsd.pkg.mk"
