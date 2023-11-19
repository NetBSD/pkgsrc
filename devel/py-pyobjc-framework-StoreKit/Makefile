# $NetBSD: Makefile,v 1.6 2023/11/19 17:03:07 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-StoreKit-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-StoreKit/}

COMMENT=	Wrappers for the framework StoreKit on macOS

NOT_FOR_PLATFORM=	Darwin-10.*-* Darwin-[0-9].*-* # 10.7+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
