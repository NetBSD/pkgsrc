# $NetBSD: Makefile,v 1.31 2013/10/06 14:13:10 wiz Exp $

DISTNAME=	libmatroska-1.4.1
PKGREVISION=	1
CATEGORIES=	multimedia devel
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.matroska.org/
COMMENT=	Extensible open standard Audio/Video container format
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
TEST_TARGET=		test

# remove CRs: fixes patching on Darwin and stops pkglint from complaining
pre-patch:
	cd ${WRKSRC}/make/linux && \
		${TR} -d '\r' < Makefile > Makefile.new && \
		${MV} Makefile.new Makefile

.include "../../devel/libebml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
