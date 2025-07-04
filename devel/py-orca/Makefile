# $NetBSD: Makefile,v 1.5 2025/07/04 09:08:33 wiz Exp $

DISTNAME=	orca-1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/orca/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/UDST/orca
COMMENT=	Python library for task orchestration
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.15.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-tables>=3.1:../../math/py-tables
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.8.1:../../devel/py-toolz

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
