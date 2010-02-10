# $NetBSD: Makefile,v 1.19 2010/02/10 19:17:44 joerg Exp $

DISTNAME=	Botan-1.8.7
PKGNAME=	botan-1.8.7
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://files.randombit.net/botan/archive/v1.8/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://botan.randombit.net/
COMMENT=	Portable, easy to use, and efficient C++ crypto library

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
REPLACE_PYTHON+=	configure.pl
USE_LANGUAGES=		c++

PYTHON_FOR_BUILD_ONLY=	yes

CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	./configure.py
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

MAKE_FLAGS+=	LIB_OPT=${CXXFLAGS:Q}

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	x86 x86_64

.if ${MACHINE_ARCH} == "x86_64"
PLIST.x86_64=	yes
PLIST.x86=	yes
.elif ${MACHINE_ARCH} == "i386"
PLIST.x86=	yes
.elif ${MACHINE_ARCH} == "powerpc"
CONFIGURE_ARGS+=	--cpu=ppc
.elif ${MACHINE_ARCH} == "powerpc64"
CONFIGURE_ARGS+=	--cpu=ppc64
.endif

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
