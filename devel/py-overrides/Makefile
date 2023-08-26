# $NetBSD: Makefile,v 1.1 2023/08/26 09:30:00 adam Exp $

DISTNAME=	overrides-7.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/overrides/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mkorpela/overrides
COMMENT=	Ddecorator to automatically detect mismatch when overriding a method
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.3:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
