# $NetBSD: Makefile,v 1.1 2026/09/08 09:51:09 adam Exp $

DISTNAME=	setuptools_git_versioning-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools-git-versioning/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://setuptools-git-versioning.readthedocs.io/
COMMENT=	Use git repo data for building a version number according to PEP-440
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	setuptools-git-versioning

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.0.1:../../textproc/py-tomli
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
