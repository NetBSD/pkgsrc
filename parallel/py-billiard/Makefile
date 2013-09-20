# $NetBSD: Makefile,v 1.3 2013/09/20 12:21:48 rodent Exp $

DISTNAME=	billiard-2.7.3.32
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel
MASTER_SITES=	http://pypi.python.org/packages/source/b/billiard/
FETCH_USING=	curl

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/celery/billiard
COMMENT=	Python multiprocessing fork with improvements and bugfixes
LICENSE=	modified-bsd

REPLACE_PYTHON+=	funtests/setup.py funtests/tests/test_multiprocessing.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
