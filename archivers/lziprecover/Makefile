# $NetBSD: Makefile,v 1.9 2019/01/18 10:05:39 adam Exp $

DISTNAME=	lziprecover-1.21
CATEGORIES=	archivers
MASTER_SITES=	http://download.savannah.gnu.org/releases/lzip/lziprecover/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/lzip/lziprecover.html
COMMENT=	Recovery tool for lossless data compressor based on the LZMA algorithm
LICENSE=	gnu-gpl-v2 # or later

USE_LANGUAGES=		c++
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
INFO_FILES=		yes
TEST_TARGET=		check

MAKE_FLAGS+=		CXX=${CXX:Q}
MAKE_FLAGS+=		CPPFLAGS=${CPPFLAGS:Q}
MAKE_FLAGS+=		CXXFLAGS=${CXXFLAGS:Q}
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}

.include "../../mk/bsd.pkg.mk"
