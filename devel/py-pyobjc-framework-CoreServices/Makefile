# $NetBSD: Makefile,v 1.8 2025/07/11 09:03:57 adam Exp $

PYOBJC_FRAMEWORK=	CoreServices

.include "../../devel/py-pyobjc/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-FSEvents>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-FSEvents

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
