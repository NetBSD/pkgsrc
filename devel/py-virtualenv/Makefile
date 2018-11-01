# $NetBSD: Makefile,v 1.41 2018/11/01 18:09:52 adam Exp $

DISTNAME=	virtualenv-16.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/virtualenv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://virtualenv.pypa.io/
COMMENT=	Virtual Python Environment builder
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=4.5.0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=1.3.0:../../devel/py-test-timeout

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
.endif

USE_LANGUAGES=	# none

REPLACE_PYTHON=	virtualenv.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} virtualenv virtualenv-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
