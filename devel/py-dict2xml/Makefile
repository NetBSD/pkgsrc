# $NetBSD: Makefile,v 1.6 2023/03/08 11:37:08 adam Exp $

DISTNAME=	dict2xml-1.7.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dict2xml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/delfick/python-dict2xml
COMMENT=	Small utility to convert Python dict to XML string
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.1.3:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
