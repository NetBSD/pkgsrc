# $NetBSD: Makefile,v 1.4 2025/04/23 12:45:09 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	Accessibility

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-1[0-9].*-* Darwin-[0-9].*-* # 11.0+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Quartz>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Quartz

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
