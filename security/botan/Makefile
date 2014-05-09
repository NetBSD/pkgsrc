# $NetBSD: Makefile,v 1.32 2014/05/09 07:37:17 wiz Exp $

DISTNAME=	Botan-1.8.14
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	security
MASTER_SITES=	http://files.randombit.net/botan/archive/v1.8/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://botan.randombit.net/
COMMENT=	Portable, easy to use, and efficient C++ crypto library
LICENSE=	2-clause-bsd

HAS_CONFIGURE=		yes
USE_LANGUAGES=		c++

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.8.14; 1.10 is supposedly better

CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	./configure.py
CONFIGURE_ARGS+=	--prefix=${PREFIX}

MAKE_FLAGS+=	LIB_OPT=${CXXFLAGS:Q}

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	i386 x86 x86_64 ppc arm

.if ${MACHINE_ARCH} == "x86_64"
PLIST.x86_64=	yes
PLIST.x86=	yes
.elif ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--cpu=i386
PLIST.i386=	yes
PLIST.x86=	yes
.elif ${MACHINE_ARCH} == "powerpc"
CONFIGURE_ARGS+=	--cpu=ppc
PLIST.ppc=	yes
.elif ${MACHINE_ARCH} == "powerpc64"
CONFIGURE_ARGS+=	--cpu=ppc64
PLIST.ppc=	yes
.elif ${MACHINE_ARCH} == "arm"
CONFIGURE_ARGS+=	--cpu=arm
PLIST.arm=	yes
.endif

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
