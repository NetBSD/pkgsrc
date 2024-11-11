# $NetBSD: Makefile,v 1.9 2024/11/11 07:28:05 wiz Exp $

DISTNAME=	cytoolz-0.12.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cytoolz/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/pytoolz/cytoolz
COMMENT=	Cython Toolz High performance functional utilities
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.8.0:../../devel/py-toolz

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
