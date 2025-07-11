# $NetBSD: Makefile,v 1.5 2025/07/11 09:03:55 adam Exp $

PYOBJC_FRAMEWORK=	CoreAudioKit

.include "../../devel/py-pyobjc/Makefile.common"

COMMENT=	Wrappers for the framework CoreAudioKit on macOS

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreAudio>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreAudio

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
