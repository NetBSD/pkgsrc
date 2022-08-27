# $NetBSD: Makefile,v 1.4 2022/08/27 08:27:02 adam Exp $

DISTNAME=	distlib-0.3.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/distlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/distlib
COMMENT=	Distribution utilities
LICENSE=	python-software-foundation

BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.29.0:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} tests/test_all.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
