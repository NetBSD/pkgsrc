# $NetBSD: Makefile,v 1.22 2024/03/03 11:29:09 wiz Exp $

DISTNAME=	lzip-1.24.1
CATEGORIES=	archivers
MASTER_SITES=	https://download.savannah.gnu.org/releases/lzip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/lzip/lzip.html
COMMENT=	Lossless data compressor based on the LZMA algorithm
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c++
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
INFO_FILES=		yes
TEST_TARGET=		check

MAKE_FLAGS+=		CXX=${CXX:Q}
MAKE_FLAGS+=		CPPFLAGS=${CPPFLAGS:Q}
MAKE_FLAGS+=		CXXFLAGS=${CXXFLAGS:Q}
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}

.include "../../mk/bsd.pkg.mk"
