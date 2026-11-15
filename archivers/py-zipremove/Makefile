# $NetBSD: Makefile,v 1.1 2026/11/15 20:49:55 wiz Exp $

DISTNAME=	zipremove-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zipremove/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/danny0838/zipremove
COMMENT=	Extend zipfile with remove-related capabilities
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools

USE_LANGUAGES=	# none

# https://github.com/danny0838/zipremove/issues/2
# FAILED (errors=1)

do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest -v

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
