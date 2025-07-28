# $NetBSD: Makefile,v 1.1 2025/07/28 13:15:20 dkazankov Exp $

DISTNAME=	railroad-diagrams-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/railroad-diagrams/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/tabatkins/railroad-diagrams
COMMENT=	Railroad-Diagram Generator, Python Version
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools<81:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-flake8>=6.0.0:../../devel/py-flake8

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"

.include "../../mk/bsd.pkg.mk"
