# $NetBSD: Makefile,v 1.14 2026/10/16 17:13:24 adam Exp $

DISTNAME=	pytoolconfig-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytoolconfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bageljrkhanofemus/pytoolconfig
COMMENT=	Python tool configuration
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>=1.0.5:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-packaging>=22.0:../../devel/py-packaging
# global
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=1.4.4:../../misc/py-platformdirs
# doc
DEPENDS+=	${PYPKGPREFIX}-sphinx>=4.5.0:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-tabulate>=0.8.9:../../textproc/py-tabulate
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=0.991:../../lang/py-mypy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
