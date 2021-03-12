# $NetBSD: Makefile,v 1.8 2021/03/12 13:11:50 adam Exp $

DISTNAME=	asteval-0.9.23
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asteval/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/newville/asteval
COMMENT=	Safe, minimalistic expression evaluator using ast module
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.6:../../math/py-numpy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC}/tests && ${PYTHONBIN} test_asteval.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
