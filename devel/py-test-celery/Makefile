# $NetBSD: Makefile,v 1.1 2022/02/15 16:21:11 wiz Exp $

DISTNAME=	pytest-celery-0.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-celery/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/graingert/pytest-celery
COMMENT=	Shim pytest plugin to enable celery.contrib.pytest
LICENSE=	modified-bsd

#TEST_DEPENDS+=		${PYPKGPREFIX}-test>=7.0:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

# has no tests
#do-test:
#	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
