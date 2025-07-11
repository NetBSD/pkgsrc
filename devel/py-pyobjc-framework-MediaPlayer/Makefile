# $NetBSD: Makefile,v 1.7 2025/07/11 09:04:03 adam Exp $

PYOBJC_FRAMEWORK=	MediaPlayer

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-1[0-5].*-* Darwin-[0-9].*-* # 10.12+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-AVFoundation>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-AVFoundation

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
