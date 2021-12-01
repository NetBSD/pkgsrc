# $NetBSD: Makefile,v 1.17 2021/12/01 08:44:23 adam Exp $

DISTNAME=	parso-0.8.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/parso/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davidhalter/parso
COMMENT=	Python Parser
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-docopt-[0-9]*:../../devel/py-docopt
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
