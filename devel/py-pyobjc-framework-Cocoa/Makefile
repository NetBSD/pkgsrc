# $NetBSD: Makefile,v 1.9 2025/07/11 09:03:54 adam Exp $

PYOBJC_FRAMEWORK=	Cocoa

.include "../../devel/py-pyobjc/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
