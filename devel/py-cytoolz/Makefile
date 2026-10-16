# $NetBSD: Makefile,v 1.17 2026/10/16 19:43:47 adam Exp $

DISTNAME=	cytoolz-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cytoolz/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/pytoolz/cytoolz
COMMENT=	Cython Toolz High performance functional utilities
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-git-versioning>=2.0:../../devel/py-setuptools-git-versioning
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.8.0:../../devel/py-toolz

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
