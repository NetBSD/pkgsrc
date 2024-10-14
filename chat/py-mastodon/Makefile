# $NetBSD: Makefile,v 1.16 2024/10/14 06:45:33 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-mastodon-1.5.0
PKGREVISION=	2
DISTNAME=	Mastodon.py-${PKGVERSION_NOREV}
CATEGORIES=	chat www python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Mastodon.py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/halcy/Mastodon.py
COMMENT=	Python wrapper for the Mastodon API
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

DEPENDS+=	${PYPKGPREFIX}-blurhash>=1.1.4:../../graphics/py-blurhash
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-decorator>=4.0.0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-http_ece>=1.0.5:../../www/py-http_ece
DEPENDS+=	${PYPKGPREFIX}-magic-[0-9]*:../../sysutils/py-magic
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.4.2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

TEST_DEPENDS+=	${PYPKGPREFIX}-contextlib2-[0-9]*:../../devel/py-contextlib2
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock-[0-9]*:../../devel/py-requests-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-vcrpy-[0-9]*:../../www/py-vcrpy
TEST_DEPENDS+=	${PYPKGPREFIX}-wrapt-[0-9]*:../../devel/py-wrapt
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

# as of 1.5.0
# 81 failed, 156 passed, 3 skipped, 3 xfailed, 104 warnings, 31 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
