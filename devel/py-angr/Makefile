# $NetBSD: Makefile,v 1.1.2.1 2018/05/19 08:50:46 spz Exp $

DISTNAME=	angr-7.8.2.21
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=angr/}
GITHUB_PROJECT=	angr
GITHUB_TAG=	000718deab49cf506f6d26d69c63215cbcf1eb5b

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/angr/
COMMENT=	Platform-agnostic binary analysis framework
LICENSE=	2-clause-bsd

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake

MAKE_FLAGS+=	LIBDIR=${LIBDIR:Q}

DEPENDS+=	${PYPKGPREFIX}-cachetools-[0-9]*:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-capstone-[0-9]*:../../devel/py-capstone
DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cle-[0-9]*:../../devel/py-cle
DEPENDS+=	${PYPKGPREFIX}-futures-[0-9]*:../../devel/py-futures
DEPENDS+=	${PYPKGPREFIX}-pyvex-[0-9]*:../../devel/py-pyvex
DEPENDS+=	${PYPKGPREFIX}-unicorn-[0-9]*:../../emulators/py-unicorn
DEPENDS+=	${PYPKGPREFIX}-claripy-[0-9]*:../../math/py-claripy

PYTHON_VERSIONS_ACCEPTED=	27

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

.include "../../devel/py-pyvex/buildlink3.mk"
.include "../../emulators/unicorn/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
