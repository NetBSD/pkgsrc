# $NetBSD: Makefile,v 1.12 2016/02/26 09:41:05 jperkin Exp $

DISTNAME=	Botan-1.11.16
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	security
MASTER_SITES=	http://botan.randombit.net/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://botan.randombit.net/
COMMENT=	Portable, easy to use, and efficient C++ crypto library
LICENSE=	2-clause-bsd

HAS_CONFIGURE=		yes
USE_LANGUAGES=		c++

PYTHON_FOR_BUILD_ONLY=	yes

CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	./configure.py
CONFIGURE_ARGS+=	--prefix=${PREFIX} --with-zlib --with-boost --destdir=${DESTDIR}${PREFIX}

REPLACE_PYTHON+=	*.py src/scripts/*.py

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CONFIGURE_ARGS+=	--cc-bin=${CXX} --cc=clang
.endif

MAKE_FLAGS+=	LIB_OPT=${CXXFLAGS:Q}

USE_TOOLS+=	gmake

PY_PATCHPLIST=	yes

PLIST_VARS+=	x86 x86_64

.if ${MACHINE_ARCH} == "x86_64"
PLIST.x86_64=	yes
PLIST.x86=	yes
CONFIGURE_ARGS+=	--cpu=x86_64
.elif ${MACHINE_ARCH} == "i386"
PLIST.x86=	yes
.endif

OPSYSVARS+=		MAKE_FLAGS
MAKE_FLAGS.SunOS+=	USER_APP_LINKS_TO=-lnsl

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
