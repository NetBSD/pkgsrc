# $NetBSD: Makefile,v 1.3 2026/06/23 05:34:55 adam Exp $

DISTNAME=	vcs_versioning-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vcs_versioning/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools-scm
COMMENT=	Manage your versions by vcs metadata
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-packaging>=20:../../devel/py-packaging

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	vcs-versioning

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1:../../textproc/py-tomli
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=0:../../devel/py-typing-extensions
.endif

# as of 1.1.1
# 3 failed, 297 passed, 109 skipped, 3 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
