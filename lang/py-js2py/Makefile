# $NetBSD: Makefile,v 1.10 2023/07/01 08:37:37 wiz Exp $

DISTNAME=	Js2Py-0.74
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=J/Js2Py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PiotrDabkowski/Js2Py
COMMENT=	Pure Python JavaScript Translator/Interpreter
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-jsparser>=2.5.1:../../lang/py-jsparser
DEPENDS+=	${PYPKGPREFIX}-six>=1.10:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=1.2:../../time/py-tzlocal
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
# needed in some workflows, and for tests, but not required by the package
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy>=0:../../math/py-numpy
TEST_DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
