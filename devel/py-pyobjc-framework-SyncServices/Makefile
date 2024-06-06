# $NetBSD: Makefile,v 1.7 2024/06/06 14:48:43 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_SyncServices-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-SyncServices/}

COMMENT=	Wrappers for the framework SyncServices on macOS

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreData>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreData

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
