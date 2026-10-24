# $NetBSD: Makefile,v 1.6 2026/10/24 10:18:46 adam Exp $

DISTNAME=	pylru-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylru/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jlhutch/pylru
COMMENT=	Implementation of a least recently used (LRU) cache
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
