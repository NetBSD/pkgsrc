# $NetBSD: Makefile,v 1.5 2025/07/11 09:04:07 adam Exp $

PYOBJC_FRAMEWORK=	ScreenCaptureKit

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-20.*-* Darwin-1[0-9].*-* Darwin-[0-9].*-* # 12.3+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreMedia>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreMedia

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
