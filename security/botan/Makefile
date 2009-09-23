# $NetBSD: Makefile,v 1.15 2009/09/23 16:36:30 jmmv Exp $

DISTNAME=	Botan-1.8.7
PKGNAME=	botan-1.8.7
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

.if ${MACHINE_ARCH} == "amd64"
PLIST_SUBST+=		AMD64=
PLIST_SUBST+=		AMD64_OR_IA32=
.elif ${MACHINE_ARCH} == "i386"
PLIST_SUBST+=		AMD64="@comment "
PLIST_SUBST+=		AMD64_OR_IA32=
.else
PLIST_SUBST+=		AMD64="@comment "
PLIST_SUBST+=		AMD64_OR_IA32="@comment "
.endif

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
