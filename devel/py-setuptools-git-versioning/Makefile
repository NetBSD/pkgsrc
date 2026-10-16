# $NetBSD: Makefile,v 1.3 2026/10/16 18:00:37 adam Exp $

DISTNAME=	setuptools_git_versioning-3.2.0
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

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
