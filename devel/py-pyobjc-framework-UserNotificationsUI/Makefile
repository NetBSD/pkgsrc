# $NetBSD: Makefile,v 1.3 2024/06/06 14:48:44 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_UserNotificationsUI-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-UserNotificationsUI/}

COMMENT=	Wrappers for the framework UserNotificationsUI on macOS

NOT_FOR_PLATFORM=	Darwin-1[0-9].*-* Darwin-[0-9].*-* # 11.0+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-UserNotifications>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-UserNotifications

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
