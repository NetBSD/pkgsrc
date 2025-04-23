# $NetBSD: Makefile,v 1.7 2025/04/23 12:45:13 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	CoreServices

.include "../../devel/py-pyobjc/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-FSEvents>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-FSEvents

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
