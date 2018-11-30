# $NetBSD: Makefile,v 1.3 2018/11/30 12:20:44 adam Exp $

DISTNAME=	joblib-0.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/joblib/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pythonhosted.org/joblib/
COMMENT=	Set of tools to provide lightweight pipelining
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/joblib && pytest-${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
