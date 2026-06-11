# $NetBSD: Makefile,v 1.11 2026/06/11 07:23:51 wiz Exp $

.include "../../devel/capstone/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for capstone
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/capstone-${GITHUB_TAG}
PYSETUPSUBDIR=	bindings/python

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

# as of 5.0.9
# 2 failed, 24 passed, 1 error

.include "../../devel/capstone/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
