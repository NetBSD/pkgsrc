# $NetBSD: Makefile,v 1.2 2026/07/13 11:13:50 wiz Exp $
#
# Changelogs: https://github.com/toumorokoshi/deepmerge/releases

DISTNAME=	deepmerge-2.1.0
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
