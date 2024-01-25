# $NetBSD: Makefile,v 1.4 2024/01/25 09:22:29 nros Exp $

DISTNAME=	lzlib-1.14
CATEGORIES=	archivers devel
MASTER_SITES=	https://download.savannah.gnu.org/releases/lzip/lzlib/

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://www.nongnu.org/lzip/lzlib.html
COMMENT=	In-memory LZMA compression and decompression library
LICENSE=	2-clause-bsd

HAS_CONFIGURE=	yes

USE_TOOLS+=	gmake

INFO_FILES=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX} --infodir=${PREFIX}/${PKGINFODIR} --enable-shared

BUILDLINK_TRANSFORM.SunOS+=	opt:-Wl,--soname=liblz.so.1:-Wl,-soname,liblz.so.1

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
