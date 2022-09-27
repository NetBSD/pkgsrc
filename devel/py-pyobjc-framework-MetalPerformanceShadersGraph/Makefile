# $NetBSD: Makefile,v 1.1 2022/09/27 18:12:56 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-MetalPerformanceShadersGraph-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-MetalPerformanceShadersGraph/}

COMMENT=	Wrappers for the framework MetalPerformanceShadersGraph on macOS

NOT_FOR_PLATFORM=	Darwin-1[0-9].*-* Darwin-[0-9].*-* # 11.0+

USE_LANGUAGES=	c objc

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-MetalPerformanceShaders>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-MetalPerformanceShaders

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
