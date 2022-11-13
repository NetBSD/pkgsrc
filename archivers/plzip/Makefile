# $NetBSD: Makefile,v 1.2 2022/11/13 16:13:53 fcambus Exp $

DISTNAME=	plzip-1.10
CATEGORIES=	archivers
MASTER_SITES=	https://download.savannah.gnu.org/releases/lzip/plzip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/lzip/plzip.html
COMMENT=	Multi-threaded data compressor based on lzlib
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c++

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	CXXFLAGS="${CFLAGS}"
CONFIGURE_ARGS+=	LDFLAGS="${LDFLAGS}"

INFO_FILES=	yes

TEST_TARGET=	check

.include "../../archivers/lzlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
