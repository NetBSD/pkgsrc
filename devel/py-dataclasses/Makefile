# $NetBSD: Makefile,v 1.1 2021/05/25 10:08:12 adam Exp $

DISTNAME=	dataclasses-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dataclasses/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ericvsmith/dataclasses
COMMENT=	Backport of the dataclasses module for Python 3.6
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	36

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -s test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
