# $NetBSD: Makefile,v 1.5 2024/06/06 14:48:36 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_GameplayKit-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-GameplayKit/}

COMMENT=	Wrappers for the framework GameplayKit on macOS

NOT_FOR_PLATFORM=	Darwin-1[0-4].*-* Darwin-[0-9].*-* # 10.11+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-SpriteKit>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-SpriteKit

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
