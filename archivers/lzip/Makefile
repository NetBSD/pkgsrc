# $NetBSD: Makefile,v 1.9 2013/10/10 12:03:03 adam Exp $

DISTNAME=	lzip-1.15
CATEGORIES=	archivers
MASTER_SITES=	http://download.savannah.gnu.org/releases/lzip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/lzip/lzip.html
COMMENT=	Lossless data compressor based on the LZMA algorithm
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c++
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
INFO_FILES=		YES

MAKEFLAGS+=		CXX=${CXX:Q} CPPFLAGS=${CPPFLAGS:Q}
MAKEFLAGS+=		CXXFLAGS=${CXXFLAGS:Q} LDFLAGS=${LDFLAGS:Q}

.include "../../mk/bsd.pkg.mk"
