# $NetBSD: Makefile,v 1.21 2026/10/26 07:39:21 wiz Exp $

DISTNAME=	xgboost-3.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xgboost/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dmlc/xgboost
COMMENT=	XGBoost Python Package
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build-core>=0.11.0:../../devel/py-scikit-build-core
DEPENDS+=	${PYPKGPREFIX}-scipy>=0:../../math/py-scipy

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		cmake
GCC_REQD+=		8

PYTHON_VERSIONS_INCOMPATIBLE=	311

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
