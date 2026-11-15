# $NetBSD: Makefile,v 1.2 2026/11/15 21:38:11 wiz Exp $

DISTNAME=	spdx_tools-0.8.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spdx_tools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spdx/tools-python
COMMENT=	SPDX parser and tools
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-beartype>=0:../../devel/py-beartype
DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-license-expression>=0:../../devel/py-license-expression
DEPENDS+=	${PYPKGPREFIX}-ply>=0:../../devel/py-ply
DEPENDS+=	${PYPKGPREFIX}-yaml>=0:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-rdflib>=0:../../textproc/py-rdflib
DEPENDS+=	${PYPKGPREFIX}-shacl>=0:../../textproc/py-shacl
DEPENDS+=	${PYPKGPREFIX}-semantic_version>=0:../../devel/py-semantic_version
DEPENDS+=	${PYPKGPREFIX}-uritools>=0:../../www/py-uritools
DEPENDS+=	${PYPKGPREFIX}-xmltodict>=0:../../textproc/py-xmltodict

USE_LANGUAGES=	# none

# as of 0.8.5
# 1029 passed, 4 skipped, 3 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
