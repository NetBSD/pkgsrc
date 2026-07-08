# $NetBSD: Makefile,v 1.5 2026/07/08 09:10:15 adam Exp $

DISTNAME=	pylru-1.3.1
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
