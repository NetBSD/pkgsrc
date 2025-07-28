# $NetBSD: Makefile,v 1.1 2025/07/28 12:56:12 dkazankov Exp $

DISTNAME=	funcy-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/funcy/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/Suor/funcy
COMMENT=	A collection of fancy functional tools focused on practicality
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"

.include "../../mk/bsd.pkg.mk"
