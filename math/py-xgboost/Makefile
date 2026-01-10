# $NetBSD: Makefile,v 1.16 2026/01/10 11:39:10 adam Exp $

DISTNAME=	xgboost-3.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xgboost/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dmlc/xgboost
COMMENT=	XGBoost Python Package
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.12.1:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		cmake ninja
GCC_REQD+=		8.1

PYTHON_VERSIONS_INCOMPATIBLE=	310

# as of 2.1.4:
# NotImplementedError: System SunOS not supported
BROKEN_ON_PLATFORM+=	SunOS-*-*

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
post-install: fix-lib-name
.PHONY: fix-lib-name
fix-lib-name:
	install_name_tool -id ${PREFIX}/${PYSITELIB}/xgboost/lib/libxgboost.dylib \
	${DESTDIR}${PREFIX}/${PYSITELIB}/xgboost/lib/libxgboost.dylib
.endif
post-install:
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/xgboost/libpath.py.orig

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
