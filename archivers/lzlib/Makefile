# $NetBSD: Makefile,v 1.3 2022/11/21 18:20:40 jperkin Exp $

DISTNAME=	lzlib-1.13
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
