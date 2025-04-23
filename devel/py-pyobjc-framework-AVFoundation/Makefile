# $NetBSD: Makefile,v 1.7 2025/04/23 12:45:10 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	AVFoundation

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-10.*-* Darwin-[0-9].*-* # 10.7+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreAudio>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreAudio
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreMedia>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreMedia
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Quartz>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Quartz

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
