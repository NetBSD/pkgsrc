# $NetBSD: Makefile,v 1.6 2023/11/19 17:02:52 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-Cocoa-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-Cocoa/}

COMMENT=	Wrappers for the framework Cocoa on macOS

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
