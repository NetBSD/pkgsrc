# $NetBSD: Makefile,v 1.9 2022/02/07 20:57:20 adam Exp $

DISTNAME=	fs-2.4.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	filesystems python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyFilesystem/pyfilesystem2
COMMENT=	Python's filesystem abstraction layer
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.3:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-six>=1.10:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized
TEST_DEPENDS+=	${PYPKGPREFIX}-pyftpdlib-[0-9]*:../../net/py-pyftpdlib
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-backports.os>=0.1:../../devel/py-backports.os
DEPENDS+=	${PYPKGPREFIX}-enum34>=1.1.6:../../devel/py-enum34
DEPENDS+=	${PYPKGPREFIX}-typing>=3.6:../../devel/py-typing
.else
PYSETUPTESTTARGET=	pytest
.endif

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
