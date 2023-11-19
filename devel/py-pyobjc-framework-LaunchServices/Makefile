# $NetBSD: Makefile,v 1.7 2023/11/19 17:02:59 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-LaunchServices-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-LaunchServices/}

COMMENT=	Wrappers for the framework LaunchServices on macOS

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreServices>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreServices

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
