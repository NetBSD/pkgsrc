# $NetBSD: Makefile,v 1.8 2025/02/05 08:05:39 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_Quartz-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-Quartz/}

COMMENT=	Wrappers for the framework Quartz on macOS

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

# 'CGWindowListCreateImageFromArray' is unavailable: obsoleted in macOS 15.0  
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS_VERSION} >= 150000
MAKE_ENV+=      MACOSX_DEPLOYMENT_TARGET=14.0
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
