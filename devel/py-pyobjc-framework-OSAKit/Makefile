# $NetBSD: Makefile,v 1.1 2022/09/27 18:12:58 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-OSAKit-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-OSAKit/}

COMMENT=	Wrappers for the framework OSAKit on macOS

USE_LANGUAGES=	c objc

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
