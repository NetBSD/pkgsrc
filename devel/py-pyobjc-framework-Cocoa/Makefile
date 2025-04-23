# $NetBSD: Makefile,v 1.8 2025/04/23 12:45:12 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	Cocoa

.include "../../devel/py-pyobjc/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
