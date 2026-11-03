# $NetBSD: Makefile,v 1.1 2026/11/03 09:24:53 adam Exp $

PYOBJC_FRAMEWORK=	StateReporting

.include "../../devel/py-pyobjc/Makefile.common"

ONLY_FOR_PLATFORM=	Darwin-2[789].*-*

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
