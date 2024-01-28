# $NetBSD: Makefile,v 1.7 2024/01/28 08:21:07 wiz Exp $

DISTNAME=	xgboost-2.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xgboost/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dmlc/xgboost
COMMENT=	XGBoost Python Package
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.12.1:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy

USE_LANGUAGES+=	c gnu++17
USE_TOOLS+=	cmake ninja
GCC_REQD+=	8.1

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

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
