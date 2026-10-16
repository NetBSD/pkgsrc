# $NetBSD: Makefile,v 1.57 2026/10/16 18:00:06 adam Exp $

DISTNAME=	setuptools_scm-10.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools_scm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools_scm
COMMENT=	Manage your versions by scm tags
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-packaging>=20:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-vcs-versioning>=2.5.0:../../devel/py-vcs-versioning
TEST_DEPENDS+=	git-base>=0:../../devel/git-base
TEST_DEPENDS+=	${PYPKGPREFIX}-mercurial>=0:../../devel/py-mercurial
TEST_DEPENDS+=	${PYPKGPREFIX}-pip>=0:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=0:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20:../../devel/py-virtualenv

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	setuptools-scm

# test status as of 10.3.4
# 4 failed, 199 passed, 8 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
