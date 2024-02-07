# $NetBSD: Makefile,v 1.7 2024/02/07 09:46:36 adam Exp $

.include "../../devel/capstone/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for capstone
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/capstone-${GITHUB_TAG}
PYSETUPSUBDIR=	bindings/python

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/capstone/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
