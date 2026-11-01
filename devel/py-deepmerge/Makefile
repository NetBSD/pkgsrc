# $NetBSD: Makefile,v 1.5 2026/11/01 21:34:22 wiz Exp $
#
# Changelogs: https://github.com/toumorokoshi/deepmerge/releases

DISTNAME=	deepmerge-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deepmerge/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://deepmerge.readthedocs.io/en/latest/
COMMENT=	Toolset to deeply merge Python dictionaries
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
