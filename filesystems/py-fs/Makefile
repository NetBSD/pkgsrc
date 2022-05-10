# $NetBSD: Makefile,v 1.11 2022/05/10 05:42:57 adam Exp $

DISTNAME=	fs-2.4.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	filesystems python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyFilesystem/pyfilesystem2
COMMENT=	Python's filesystem abstraction layer
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.3:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-six>=1.10:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized
TEST_DEPENDS+=	${PYPKGPREFIX}-pyftpdlib-[0-9]*:../../net/py-pyftpdlib
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

PYTHON_VERSIONS_INCOMPATIBLE=	27

PYSETUPTESTTARGET=	pytest

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
