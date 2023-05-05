# $NetBSD: Makefile,v 1.2 2023/05/05 12:49:57 jperkin Exp $

DISTNAME=	cattrs-22.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cattrs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-attrs/cattrs
COMMENT=	Composable complex class support for attrs and dataclasses
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-attrs>=20:../../devel/py-attrs
# no tests included in pypi distfile
#TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=0:../../devel/py-test-benchmark

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 308
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=0:../../devel/py-typing-extensions
.endif
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=0:../../devel/py-exceptiongroup
.endif

#do-test:
#	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
