# $NetBSD: Makefile,v 1.2 2023/11/19 17:03:02 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-Network-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-Network/}

COMMENT=	Wrappers for the framework Network on macOS

NOT_FOR_PLATFORM=	Darwin-1[0-7].*-* Darwin-[0-9].*-* # 10.14+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
