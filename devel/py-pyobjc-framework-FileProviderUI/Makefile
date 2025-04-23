# $NetBSD: Makefile,v 1.4 2025/04/23 12:45:15 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	FileProviderUI

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-1[0-8].*-* Darwin-[0-9].*-* # 10.15+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-FileProvider>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-FileProvider

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
