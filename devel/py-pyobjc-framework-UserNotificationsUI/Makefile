# $NetBSD: Makefile,v 1.2 2023/11/19 17:03:08 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-UserNotificationsUI-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-UserNotificationsUI/}

COMMENT=	Wrappers for the framework UserNotificationsUI on macOS

NOT_FOR_PLATFORM=	Darwin-1[0-9].*-* Darwin-[0-9].*-* # 11.0+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-UserNotifications>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-UserNotifications

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
