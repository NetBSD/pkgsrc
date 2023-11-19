# $NetBSD: Makefile,v 1.2 2023/11/19 17:03:05 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-SharedWithYou-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-SharedWithYou/}

COMMENT=	Wrappers for the framework SharedWithYou on macOS

NOT_FOR_PLATFORM=	Darwin-2[0-1].*-* Darwin-1[0-9].*-* Darwin-[0-9].*-* # 13+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-SharedWithYouCore>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-SharedWithYouCore

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
