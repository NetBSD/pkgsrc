# $NetBSD: Makefile,v 1.12 2024/02/08 10:15:24 adam Exp $

DISTNAME=	kazoo-2.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kazoo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kazoo.readthedocs.org/
COMMENT=	Higher level Zookeeper client
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=46.4.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
# TODO:
#TEST_DEPENDS+=	${PYPKGPREFIX}-pyjks

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
