# $NetBSD: Makefile,v 1.10 2025/04/23 12:45:21 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	PubSub

.include "../../devel/py-pyobjc/Makefile.common"

ONLY_FOR_PLATFORM=	Darwin-[0-9].*-* Darwin-1[0-8].*-* # -10.14

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
