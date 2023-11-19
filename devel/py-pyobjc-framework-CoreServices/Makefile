# $NetBSD: Makefile,v 1.5 2023/11/19 17:02:54 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-CoreServices-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-CoreServices/}

COMMENT=	Wrappers for the framework CoreServices on macOS

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-FSEvents>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-FSEvents

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
