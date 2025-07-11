# $NetBSD: Makefile,v 1.5 2025/07/11 09:03:59 adam Exp $

PYOBJC_FRAMEWORK=	FileProviderUI

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-1[0-8].*-* Darwin-[0-9].*-* # 10.15+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-FileProvider>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-FileProvider

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
