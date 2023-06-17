# $NetBSD: Makefile,v 1.1 2023/06/17 17:41:50 wiz Exp $

DISTNAME=	plaster-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/plaster/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.pylonsproject.org/projects/plaster/en/latest/
COMMENT=	Loader interface around multiple config file formats
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
