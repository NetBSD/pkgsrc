# $NetBSD: Makefile,v 1.5 2025/07/11 09:04:01 adam Exp $

PYOBJC_FRAMEWORK=	IntentsUI

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-20.*-* Darwin-1[0-9].*-* Darwin-[0-9].*-* # 12.0+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Intents>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Intents

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
