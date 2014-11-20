# $NetBSD: Makefile,v 1.10 2014/11/20 07:32:15 mef Exp $

DISTNAME=	lzip-1.16
CATEGORIES=	archivers
MASTER_SITES=	http://download.savannah.gnu.org/releases/lzip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/lzip/lzip.html
COMMENT=	Lossless data compressor based on the LZMA algorithm
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c++
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
INFO_FILES=		YES

MAKEFLAGS+=		CXX=${CXX:Q} CPPFLAGS=${CPPFLAGS:Q}
MAKEFLAGS+=		CXXFLAGS=${CXXFLAGS:Q} LDFLAGS=${LDFLAGS:Q}

.include "../../mk/bsd.pkg.mk"
