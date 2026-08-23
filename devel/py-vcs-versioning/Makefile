# $NetBSD: Makefile,v 1.10 2026/08/23 08:23:11 wiz Exp $

DISTNAME=	vcs_versioning-2.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vcs_versioning/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools-scm
COMMENT=	Manage your versions by vcs metadata
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-packaging>=20:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=0:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=0:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial
TEST_DEPENDS+=	jj-[0-9]*:../../devel/jj

USE_TOOLS+=	git:test

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	vcs-versioning

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1:../../textproc/py-tomli
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=0:../../devel/py-typing-extensions
.endif

# as of 2.3.1
# 1 failed, 647 passed, 9 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
