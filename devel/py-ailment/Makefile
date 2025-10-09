# $NetBSD: Makefile,v 1.14 2025/10/09 08:01:56 wiz Exp $

.include "../../devel/py-angr/version.mk"

DISTNAME=	ailment-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ailment/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/angr/ailment
COMMENT=	The angr intermediate language
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# Circular dependency
#TEST_DEPENDS+=	${PYPKGPREFIX}-angr-[0-9]*:../../devel/py-angr
TEST_DEPENDS+=	${PYPKGPREFIX}-archinfo-[0-9]*:../../devel/py-archinfo
TEST_DEPENDS+=	${PYPKGPREFIX}-pyvex-[0-9]*:../../devel/py-pyvex

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
