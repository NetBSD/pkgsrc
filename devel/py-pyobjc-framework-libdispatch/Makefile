# $NetBSD: Makefile,v 1.7 2025/07/11 09:04:02 adam Exp $

PYOBJC_FRAMEWORK=	libdispatch

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-1[0-1].*-* Darwin-[0-9].*-* # 10.8+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
