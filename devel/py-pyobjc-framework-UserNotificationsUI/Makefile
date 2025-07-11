# $NetBSD: Makefile,v 1.5 2025/07/11 09:04:10 adam Exp $

PYOBJC_FRAMEWORK=	UserNotificationsUI

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-1[0-9].*-* Darwin-[0-9].*-* # 11.0+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-UserNotifications>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-UserNotifications

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
