# $NetBSD: Makefile,v 1.2 2022/11/13 16:15:13 fcambus Exp $

DISTNAME=	tarlz-0.22
CATEGORIES=	archivers
MASTER_SITES=	https://download.savannah.gnu.org/releases/lzip/tarlz/
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://lzip.nongnu.org/tarlz.html
COMMENT=	Combined implementation of tar archiver and lzip compressor
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
