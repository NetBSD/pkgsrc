# $NetBSD: Makefile,v 1.37 2023/08/01 23:20:47 wiz Exp $

DISTNAME=	networkx-3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/networkx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://networkx.github.io/
COMMENT=	Python package for creating and manipulating graphs and networks
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} networkx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
