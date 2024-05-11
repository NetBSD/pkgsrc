# $NetBSD: Makefile,v 1.19 2024/05/11 19:08:53 adam Exp $

DISTNAME=	joblib-1.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/joblib/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://joblib.readthedocs.io/
COMMENT=	Set of tools to provide lightweight pipelining
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
