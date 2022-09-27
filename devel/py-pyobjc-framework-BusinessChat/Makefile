# $NetBSD: Makefile,v 1.1 2022/09/27 18:12:48 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-BusinessChat-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-BusinessChat/}

COMMENT=	Wrappers for the framework BusinessChat on macOS

NOT_FOR_PLATFORM=	Darwin-1[0-7].*-* Darwin-[0-9].*-* # 10.14+

USE_LANGUAGES=	c objc

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
