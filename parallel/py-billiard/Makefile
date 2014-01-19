# $NetBSD: Makefile,v 1.8 2014/01/19 18:48:00 wiz Exp $

DISTNAME=	billiard-3.3.0.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel
MASTER_SITES=	https://pypi.python.org/packages/source/b/billiard/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/celery/billiard
COMMENT=	Python multiprocessing fork with improvements and bugfixes
LICENSE=	modified-bsd

USE_LANGUAGES+=	c
REPLACE_PYTHON+=	funtests/setup.py funtests/tests/test_multiprocessing.py

PYTHON_VERSIONS_INCOMPATIBLE=	26

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
