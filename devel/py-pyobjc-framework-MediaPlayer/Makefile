# $NetBSD: Makefile,v 1.6 2025/04/23 12:45:18 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	MediaPlayer

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-1[0-5].*-* Darwin-[0-9].*-* # 10.12+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-AVFoundation>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-AVFoundation

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
