# $NetBSD: Makefile,v 1.3 2026/08/23 08:06:20 wiz Exp $
#
# Changelogs: https://github.com/toumorokoshi/deepmerge/releases

DISTNAME=	deepmerge-3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deepmerge/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://deepmerge.readthedocs.io/en/latest/
COMMENT=	Toolset to deeply merge Python dictionaries
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
