# $NetBSD: Makefile,v 1.4 2025/04/23 12:45:22 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	ScreenCaptureKit

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-20.*-* Darwin-1[0-9].*-* Darwin-[0-9].*-* # 12.3+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreMedia>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreMedia

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
