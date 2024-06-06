# $NetBSD: Makefile,v 1.3 2024/06/06 14:48:32 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_CoreAudioKit-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-CoreAudioKit/}

COMMENT=	Wrappers for the framework CoreAudioKit on macOS

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreAudio>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreAudio

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
