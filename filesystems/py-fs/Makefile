# $NetBSD: Makefile,v 1.15 2025/04/14 11:54:31 adam Exp $

DISTNAME=	fs-2.4.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	filesystems python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyFilesystem/pyfilesystem2
COMMENT=	Python's filesystem abstraction layer
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.3:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-six>=1.10:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized
TEST_DEPENDS+=	${PYPKGPREFIX}-pyftpdlib-[0-9]*:../../net/py-pyftpdlib
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
# 24 failed, 2377 passed, 26 skipped, 43 warnings

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
