# $NetBSD: Makefile,v 1.5 2019/10/31 10:24:52 adam Exp $

DISTNAME=	joblib-0.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/joblib/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://joblib.readthedocs.io/
COMMENT=	Set of tools to provide lightweight pipelining
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/joblib && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
