# $NetBSD: Makefile,v 1.4 2022/01/25 21:51:58 wiz Exp $

DISTNAME=	flit_core-3.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flit-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flit.readthedocs.io/
COMMENT=	Distribution-building parts of Flit
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath>=0:../../devel/py-testpath

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
