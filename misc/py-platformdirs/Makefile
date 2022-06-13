# $NetBSD: Makefile,v 1.7 2022/06/13 19:29:44 adam Exp $

DISTNAME=	platformdirs-2.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/platformdirs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/platformdirs/platformdirs
COMMENT=	Python module for determining appropriate platform-specific dirs
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0.22.0:../../devel/py-hatchling
BUILD_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>0:../../devel/py-hatch-vcs
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>0:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
