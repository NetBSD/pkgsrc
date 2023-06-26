# $NetBSD: Makefile,v 1.2 2023/06/26 11:45:48 wiz Exp $

DISTNAME=	Botan-3.0.0
PKGNAME=	${DISTNAME:S/Botan/botan3/}
CATEGORIES=	security
MASTER_SITES=	https://botan.randombit.net/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	https://botan.randombit.net/
COMMENT=	Portable, easy to use, and efficient C++ crypto library (v3)
LICENSE=	2-clause-bsd

DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts

HAS_CONFIGURE=		yes
USE_LANGUAGES=		c++
USE_TOOLS+=		gmake
GCC_REQD+=		11

PYTHON_FOR_BUILD_ONLY=	yes

CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	./configure.py
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-boost
CONFIGURE_ARGS+=	--with-bzip2
CONFIGURE_ARGS+=	--with-lzma
CONFIGURE_ARGS+=	--with-sqlite3
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--docdir=share/doc
CONFIGURE_ARGS+=	--without-sphinx
CONFIGURE_ARGS+=	--program-suffix=3
CONFIGURE_ARGS+=	--system-cert-bundle=${PREFIX}/share/mozilla-rootcerts/cacert.pem
CONFIGURE_ARGS+=	--no-install-python-module

PKGCONFIG_OVERRIDE=	src/build-data/botan.pc.in

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CONFIGURE_ARGS+=	--cc-bin=${CXX} --cc=clang
.else
CONFIGURE_ARGS+=	--cc=gcc
.endif

.if ${MACHINE_ARCH} == "x86_64"
CONFIGURE_ARGS+=	--cpu=amd64
.elif ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--cpu=i386
.elif ${MACHINE_ARCH} == "powerpc"
CONFIGURE_ARGS+=	--cpu=ppc
.elif ${MACHINE_ARCH} == "powerpc64"
CONFIGURE_ARGS+=	--cpu=ppc64
.elif ${MACHINE_ARCH:Maarch64*}
CONFIGURE_ARGS+=	--cpu=arm64
.elif ${MACHINE_ARCH:Mearm*}
CONFIGURE_ARGS+=	--cpu=arm32
.endif

MAKE_FLAGS+=	LIB_OPT=${CXXFLAGS:Q}

LDFLAGS.SunOS+=	-lnsl -lsocket

TEST_TARGET=	check

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
