# $NetBSD: Makefile,v 1.34 2013/04/12 13:35:20 drochner Exp $

DISTNAME=	libebml-1.3.0
CATEGORIES=	devel
MASTER_SITES=	http://dl.matroska.org/downloads/libebml/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/ebml/
COMMENT=	Extensible Binary Meta Language support library
LICENSE=	gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

NO_CONFIGURE=		yes
MAKEFLAGS+=		prefix=${PREFIX}
MAKE_ENV+=		CXXFLAGS=${CXXFLAGS:Q} RANLIB=${RANLIB:Q}
BUILD_DIRS=		make/linux
BUILD_TARGET=		sharedlib
INSTALL_TARGET=		install_headers install_sharedlib

# remove CRs: fixes patching on Darwin and stops pkglint from complaining
pre-patch:
	cd ${WRKSRC}/make/linux && \
		${TR} -d '\r' < Makefile > Makefile.new && \
		${MV} Makefile.new Makefile

.include "../../mk/bsd.pkg.mk"
