# $NetBSD: Makefile,v 1.6 2025/04/23 12:45:16 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	GameplayKit

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-1[0-4].*-* Darwin-[0-9].*-* # 10.11+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-SpriteKit>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-SpriteKit

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
