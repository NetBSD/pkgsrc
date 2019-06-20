# $NetBSD: Makefile,v 1.7 2019/06/20 16:31:09 adam Exp $

DISTNAME=	graphviz-0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/graphviz/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xflr6/graphviz
COMMENT=	Create and render graph descriptions in DOT language
LICENSE=	mit

DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.4:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=1.8:../../devel/py-test-mock

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/tests && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
