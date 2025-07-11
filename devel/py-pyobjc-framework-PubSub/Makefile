# $NetBSD: Makefile,v 1.11 2025/07/11 09:04:06 adam Exp $

PYOBJC_FRAMEWORK=	PubSub

.include "../../devel/py-pyobjc/Makefile.common"

ONLY_FOR_PLATFORM=	Darwin-[0-9].*-* Darwin-1[0-8].*-* # -10.14

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
