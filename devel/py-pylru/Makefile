# $NetBSD: Makefile,v 1.3 2022/04/24 17:30:35 adam Exp $

DISTNAME=	pylru-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylru/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jlhutch/pylru
COMMENT=	Implementation of a least recently used (LRU) cache
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
