# $NetBSD: Makefile,v 1.4 2025/04/23 12:45:14 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	DiscRecordingUI

.include "../../devel/py-pyobjc/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-DiscRecording>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-DiscRecording

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
