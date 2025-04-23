# $NetBSD: Makefile,v 1.6 2025/04/23 12:45:13 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	CoreMedia

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-10.*-* Darwin-[0-9].*-* # 10.7+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
