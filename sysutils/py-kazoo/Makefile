# $NetBSD: Makefile,v 1.15 2026/04/14 13:35:57 adam Exp $

DISTNAME=	kazoo-2.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kazoo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kazoo.readthedocs.org/
COMMENT=	Higher level Zookeeper client
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
# TODO:
#TEST_DEPENDS+=	${PYPKGPREFIX}-pyjks

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
