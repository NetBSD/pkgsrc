# $NetBSD: Makefile,v 1.5 2022/09/27 18:13:00 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-ScreenSaver-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-ScreenSaver/}

COMMENT=	Wrappers for the framework ScreenSaver on macOS

USE_LANGUAGES=	c objc

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
