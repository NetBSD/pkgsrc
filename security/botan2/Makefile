# $NetBSD: Makefile,v 1.10 2024/02/26 21:01:13 nros Exp $

DISTNAME=	Botan-2.19.4
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	security
MASTER_SITES=	https://botan.randombit.net/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://botan.randombit.net/
COMMENT=	Portable, easy to use, and efficient C++ crypto library (v2)
LICENSE=	2-clause-bsd

HAS_CONFIGURE=		yes
USE_LANGUAGES=		c++

PYTHON_FOR_BUILD_ONLY=	yes

CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	./configure.py
CONFIGURE_ARGS+=	--prefix=${PREFIX} --with-zlib --with-boost
CONFIGURE_ARGS+=	--docdir=share/doc
CONFIGURE_ARGS+=	--without-sphinx

REPLACE_PYTHON+=	*.py src/scripts/*.py

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CONFIGURE_ARGS+=	--cc-bin=${CXX:Q} --cc=clang
.else
CONFIGURE_ARGS+=	--cc=gcc
.endif

PLIST_VARS+=		x86
.if ${MACHINE_ARCH} == "x86_64"
PLIST.x86=		yes
CONFIGURE_ARGS+=	--cpu=amd64
.elif ${MACHINE_ARCH} == "i386"
PLIST.x86=		yes
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

PKGCONFIG_OVERRIDE=		build/botan-2.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

MAKE_FLAGS+=	LIB_OPT=${CXXFLAGS:Q}

USE_TOOLS+=	gmake

PY_PATCHPLIST=	yes

LDFLAGS.SunOS+=	-lnsl -lsocket

TEST_TARGET=	tests

post-test:
	cd ${WRKSRC} && ./botan-test

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
