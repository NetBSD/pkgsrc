# $NetBSD: Makefile,v 1.4 2019/10/19 14:21:25 adam Exp $

DISTNAME=	asteval-0.9.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asteval/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/newville/asteval
COMMENT=	Safe, minimalistic expression evaluator using ast module
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.6:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/tests && ${PYTHONBIN} test_asteval.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
