# $NetBSD: Makefile,v 1.25 2026/06/30 06:54:57 adam Exp $

DISTNAME=	lzip-1.26
CATEGORIES=	archivers
MASTER_SITES=	https://download.savannah.gnu.org/releases/lzip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/lzip/lzip.html
COMMENT=	Lossless data compressor based on the LZMA algorithm
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
INFO_FILES=		yes
TEST_TARGET=		check

CPPFLAGS.SCO_SV+=	-Dstrtoull=strtoul -DS_ISSOCK=S_ISBLK

MAKE_FLAGS+=		CXX=${CXX:Q}
MAKE_FLAGS+=		CPPFLAGS=${CPPFLAGS:Q}
MAKE_FLAGS+=		CXXFLAGS=${CXXFLAGS:Q}
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}

.include "../../mk/bsd.pkg.mk"
