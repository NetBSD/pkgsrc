# $NetBSD: Makefile,v 1.6 2025/04/23 12:45:16 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	GameCenter

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-1[0-1].*-* Darwin-[0-9].*-* # 10.8+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
