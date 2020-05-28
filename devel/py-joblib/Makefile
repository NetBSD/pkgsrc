# $NetBSD: Makefile,v 1.8 2020/05/28 12:06:28 adam Exp $

DISTNAME=	joblib-0.15.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/joblib/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://joblib.readthedocs.io/
COMMENT=	Set of tools to provide lightweight pipelining
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
