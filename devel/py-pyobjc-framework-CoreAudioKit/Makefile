# $NetBSD: Makefile,v 1.4 2025/04/23 12:45:12 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	CoreAudioKit

.include "../../devel/py-pyobjc/Makefile.common"

COMMENT=	Wrappers for the framework CoreAudioKit on macOS

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreAudio>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreAudio

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
