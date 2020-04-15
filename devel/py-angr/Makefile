# $NetBSD: Makefile,v 1.4 2020/04/15 22:50:40 joerg Exp $

DISTNAME=	angr-8.20.1.7
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=angr/}
GITHUB_PROJECT=	angr
GITHUB_TAG=	5cb726d5139537cbe7c03bc5ed540b9cdb7c7e21

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/angr/
COMMENT=	Platform-agnostic binary analysis framework
LICENSE=	2-clause-bsd

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake

MAKE_FLAGS+=	LIBDIR=${LIBDIR:Q}

DEPENDS+=	${PYPKGPREFIX}-archinfo-[0-9]*:../../devel/py-archinfo
BUILD_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
DEPENDS+=	${PYPKGPREFIX}-cachetools-[0-9]*:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-capstone-[0-9]*:../../devel/py-capstone
DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cle-[0-9]*:../../devel/py-cle
DEPENDS+=	${PYPKGPREFIX}-pyvex-[0-9]*:../../devel/py-pyvex
DEPENDS+=	${PYPKGPREFIX}-unicorn-[0-9]*:../../emulators/py-unicorn
DEPENDS+=	${PYPKGPREFIX}-claripy-[0-9]*:../../math/py-claripy

PYTHON_VERSIONS_INCOMPATIBLE=	27

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

.include "../../devel/py-pyvex/buildlink3.mk"
.include "../../emulators/unicorn/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
