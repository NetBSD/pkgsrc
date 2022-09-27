# $NetBSD: Makefile,v 1.3 2022/09/27 18:12:54 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-ImageCaptureCore-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-ImageCaptureCore/}

COMMENT=	Wrappers for the framework ImageCaptureCore on macOS

NOT_FOR_PLATFORM=	Darwin-[0-9].*-* # 10.6+

USE_LANGUAGES=	c objc

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
