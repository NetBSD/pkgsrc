# $NetBSD: Makefile,v 1.7 2026/08/04 20:28:42 wiz Exp $

DISTNAME=	lzlib-1.15
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

BUILDLINK_TRANSFORM.Darwin+=	opt:-Wl,--soname=liblz.so.1:-Wl,-install_name,${PREFIX}/lib/liblz.so.1
BUILDLINK_TRANSFORM.SunOS+=	opt:-Wl,--soname=liblz.so.1:-Wl,-soname,liblz.so.1

TEST_TARGET=	check

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
