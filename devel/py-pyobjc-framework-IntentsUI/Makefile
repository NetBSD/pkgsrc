# $NetBSD: Makefile,v 1.2 2023/11/19 17:02:59 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-IntentsUI-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-IntentsUI/}

COMMENT=	Wrappers for the framework IntentsUI on macOS

NOT_FOR_PLATFORM=	Darwin-20.*-* Darwin-1[0-9].*-* Darwin-[0-9].*-* # 12.0+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Intents>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Intents

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
