# $NetBSD: Makefile,v 1.5 2024/06/06 14:48:45 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_libdispatch-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-libdispatch/}

COMMENT=	Wrappers for the framework libdispatch on macOS

NOT_FOR_PLATFORM=	Darwin-1[0-1].*-* Darwin-[0-9].*-* # 10.8+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core


.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
