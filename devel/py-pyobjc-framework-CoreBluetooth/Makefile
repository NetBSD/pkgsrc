# $NetBSD: Makefile,v 1.6 2025/04/23 12:45:12 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	CoreBluetooth

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-1[0-3].*-* Darwin-[0-9].*-* # 10.10+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
