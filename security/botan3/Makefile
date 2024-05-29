# $NetBSD: Makefile,v 1.11 2024/05/29 16:34:13 adam Exp $

PKGREVISION= 1
.include "Makefile.common"

PKGNAME=	${DISTNAME:S/Botan/botan3/}
COMMENT=	Portable, easy to use, and efficient C++ crypto library (v3)

DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts

HAS_CONFIGURE=		yes
USE_LANGUAGES=		c++
USE_TOOLS+=		gmake
GCC_REQD+=		11
USE_CXX_FEATURES+=	c++20

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

PLIST_VARS+=		prng
.if ${MACHINE_ARCH} == "x86_64"
PLIST.prng=		yes
CONFIGURE_ARGS+=	--cpu=amd64
.elif ${MACHINE_ARCH} == "i386"
PLIST.prng=		yes
CONFIGURE_ARGS+=	--cpu=i386
.elif ${MACHINE_ARCH} == "powerpc"
CONFIGURE_ARGS+=	--cpu=ppc
.elif ${MACHINE_ARCH} == "powerpc64"
PLIST.prng=		yes
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
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.37.0
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
