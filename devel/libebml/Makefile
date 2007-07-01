# $NetBSD: Makefile,v 1.26 2007/07/01 20:20:45 heinz Exp $
#

DISTNAME=	libebml-0.7.7
CATEGORIES=	devel
MASTER_SITES=	http://dl.matroska.org/downloads/libebml/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/ebml/
COMMENT=	Extensible Binary Meta Language support library

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

.include "../../mk/bsd.pkg.mk"
