# $NetBSD: Makefile,v 1.6 2025/04/23 12:45:17 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	libdispatch

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-1[0-1].*-* Darwin-[0-9].*-* # 10.8+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
