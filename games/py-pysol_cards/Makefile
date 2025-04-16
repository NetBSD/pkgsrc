# $NetBSD: Makefile,v 1.6 2025/04/16 20:42:07 adam Exp $

DISTNAME=	pysol_cards-0.18.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysol-cards/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fc-solve.shlomifish.org/
COMMENT=	Deal PySol FC Cards
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>0:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
