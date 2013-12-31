# $NetBSD: Makefile,v 1.6 2013/12/31 15:47:24 rodent Exp $

DISTNAME=	billiard-3.3.0.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel
MASTER_SITES=	https://pypi.python.org/packages/source/b/billiard/
FETCH_USING=	curl

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/celery/billiard
COMMENT=	Python multiprocessing fork with improvements and bugfixes
LICENSE=	modified-bsd

USE_LANGUAGES+=	c
REPLACE_PYTHON+=	funtests/setup.py funtests/tests/test_multiprocessing.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
