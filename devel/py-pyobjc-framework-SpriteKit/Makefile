# $NetBSD: Makefile,v 1.4 2023/11/19 17:03:07 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-SpriteKit-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-SpriteKit/}

COMMENT=	Wrappers for the framework SpriteKit on macOS

NOT_FOR_PLATFORM=	Darwin-1[0-2].*-* Darwin-[0-9].*-* # 10.9+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Quartz>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Quartz

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
