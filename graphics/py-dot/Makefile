# $NetBSD: Makefile,v 1.14 2024/02/06 21:40:08 adam Exp $

DISTNAME=	pydot-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/erocarrera/pydot
COMMENT=	Python interface to Graphviz's Dot language
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=3:../../devel/py-pyparsing
TEST_DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/pydot_unittest.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
