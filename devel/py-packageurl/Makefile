# $NetBSD: Makefile,v 1.12 2023/08/03 08:03:19 adam Exp $

DISTNAME=	packageurl-python-0.11.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/packageurl-python/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/package-url/packageurl-python
COMMENT=	Purl aka. Package URL parser and builder
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-isort>0:../../devel/py-isort
TEST_DEPENDS+=	${PYPKGPREFIX}-test>0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
