#	$NetBSD: Makefile,v 1.1 2020/08/18 20:19:20 riastradh Exp $

DISTNAME=	progressbar2-3.51.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/progressbar2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WoLpH/python-progressbar
COMMENT=	Text progress bar library for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-utils>=0:../../devel/py-utils

TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.7.7:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=0.3.11:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.8.5:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.6.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=4.6.9:../../devel/py-test

do-test:
	${RUN} cd ${WRKSRC}/tests && \
	${SETENV} ${TEST_ENV} PYTHONPATH=${WRKSRC}/build/lib \
	pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
