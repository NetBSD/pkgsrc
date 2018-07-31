# $NetBSD: Makefile,v 1.5 2018/07/31 16:14:29 nia Exp $

VERSION=	1.2.2
DISTNAME=	Mastodon.py-${VERSION}
PKGNAME=	${PYPKGPREFIX}-mastodon-${VERSION}
CATEGORIES=	chat www python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Mastodon.py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/halcy/Mastodon.py
COMMENT=	Python wrapper for the Mastodon API
LICENSE=	mit

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-contextlib2-[0-9]*:../../devel/py-contextlib2
TEST_DEPENDS+=	${PYPKGPREFIX}-wrapt-[0-9]*:../../devel/py-wrapt
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
