# $NetBSD: Makefile,v 1.28 2008/04/28 09:48:13 wiz Exp $
#

DISTNAME=	libebml-0.7.8
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
USE_LIBTOOL=	yes

NO_CONFIGURE=	yes
MAKEFLAGS+=	prefix=${PREFIX:Q}
MAKE_ENV+=	CXXFLAGS=${CXXFLAGS:M*:Q} RANLIB=${RANLIB:Q}
BUILD_DIRS=	make/linux
BUILD_TARGET=	sharedlib
INSTALL_TARGET=	install_headers install_sharedlib

.include "../../mk/bsd.pkg.mk"
