# $NetBSD: Makefile,v 1.1 2023/06/13 17:36:58 adam Exp $

DISTNAME=	xgboost-1.7.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xgboost/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dmlc/xgboost
COMMENT=	XGBoost Python Package
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy

USE_LANGUAGES+=	c gnu++17
USE_TOOLS+=	cmake ninja

REPLACE_PYTHON+=	xgboost/dmlc-core/tracker/dmlc-submit
REPLACE_PYTHON+=	xgboost/dmlc-core/tracker/dmlc_tracker/launcher.py
REPLACE_SH+=		xgboost/dmlc-core/tracker/yarn/build.sh

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 # py-scipy

pre-configure:
	${RM} ${WRKSRC}/xgboost/include/xgboost/collective/socket.h.orig

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id ${PREFIX}/${PYSITELIB}/xgboost/lib/libxgboost.dylib \
	${DESTDIR}${PREFIX}/${PYSITELIB}/xgboost/lib/libxgboost.dylib
.endif

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
