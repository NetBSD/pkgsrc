# $NetBSD: Makefile,v 1.8 2025/04/23 12:45:24 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	SyncServices

.include "../../devel/py-pyobjc/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreData>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreData

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
