# $NetBSD: Makefile,v 1.16 2025/02/04 12:17:08 adam Exp $

DISTNAME=	pydot-3.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/erocarrera/pydot
COMMENT=	Python interface to Graphviz's Dot language
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.0:../../devel/py-setuptools
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=3.0.9:../../devel/py-pyparsing
TEST_DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
