# $NetBSD: Makefile,v 1.6 2025/04/23 12:45:11 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	CloudKit

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-1[0-3].*-* Darwin-[0-9].*-* # 10.10+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Accounts>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Accounts
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreData>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreData
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreLocation>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreLocation

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
