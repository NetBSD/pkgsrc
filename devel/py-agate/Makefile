# $NetBSD: Makefile,v 1.3 2025/04/12 08:02:08 adam Exp $

DISTNAME=	agate-1.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/agate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://agate.readthedocs.io/
COMMENT=	Python data analysis library that is optimized for humans
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-babel-[0-9]*:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-cssselect-[0-9]*:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-isodate-[0-9]*:../../time/py-isodate
DEPENDS+=	${PYPKGPREFIX}-leather>=0.3.2:../../graphics/py-leather
DEPENDS+=	${PYPKGPREFIX}-parsedatetime-[0-9]*:../../time/py-parsedatetime
DEPENDS+=	${PYPKGPREFIX}-pytimeparse-[0-9]*:../../time/py-pytimeparse
DEPENDS+=	${PYPKGPREFIX}-slugify-[0-9]*:../../devel/py-slugify
TEST_DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
