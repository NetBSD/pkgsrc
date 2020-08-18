# $NetBSD: Makefile,v 1.32 2020/08/18 20:15:04 riastradh Exp $

DISTNAME=	networkx-2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/networkx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://networkx.github.io/
COMMENT=	Python package for creating and manipulating graphs and networks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-decorator>=4.3.0:../../devel/py-decorator
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} \
	pytest-${PYVERSSUFFIX} --pyargs networkx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
