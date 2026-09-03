# $NetBSD: Makefile,v 1.54 2026/09/03 06:04:25 adam Exp $

DISTNAME=	setuptools_scm-10.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools_scm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools_scm
COMMENT=	Manage your versions by scm tags
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-packaging>=20:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-vcs-versioning>=2.3.2:../../devel/py-vcs-versioning
TEST_DEPENDS+=	git-base>=0:../../devel/git-base
TEST_DEPENDS+=	${PYPKGPREFIX}-mercurial>=0:../../devel/py-mercurial
TEST_DEPENDS+=	${PYPKGPREFIX}-pip>=0:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=0:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20:../../devel/py-virtualenv

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	setuptools-scm

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1:../../textproc/py-tomli
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.1:../../devel/py-typing-extensions
.endif

# test status as of 10.0.5
# 2 failed, 134 passed, 6 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
