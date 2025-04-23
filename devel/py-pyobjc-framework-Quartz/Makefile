# $NetBSD: Makefile,v 1.9 2025/04/23 12:45:21 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	Quartz

.include "../../devel/py-pyobjc/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

# 'CGWindowListCreateImageFromArray' is unavailable: obsoleted in macOS 15.0  
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS_VERSION} >= 150000
MAKE_ENV+=      MACOSX_DEPLOYMENT_TARGET=14.0
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
