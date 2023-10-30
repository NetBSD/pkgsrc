# $NetBSD: Makefile,v 1.5 2023/10/30 09:07:53 adam Exp $

DISTNAME=	pytoolconfig-1.2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
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

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.0.1:../../textproc/py-tomli
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
