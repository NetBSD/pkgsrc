# $NetBSD: Makefile,v 1.1 2018/07/06 03:13:36 minskim Exp $

DISTNAME=	joblib-0.12.0
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
	cd ${WRKSRC} && ${LOCALBASE}/bin/pytest-${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
