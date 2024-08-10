# $NetBSD: Makefile,v 1.40 2024/08/10 06:29:30 wiz Exp $

DISTNAME=	babel-2.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=B/Babel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://babel.pocoo.org/
COMMENT=	Collection of tools for internationalizing Python applications
LICENSE=	modified-bsd

WHEEL_NAME=	Babel-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# as of 2.15.0
# 1 failed, 5986 passed, 1074 skipped, 333 warnings

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 309
DEPENDS+=	${PYPKGPREFIX}-pytz>=2015.7:../../time/py-pytz
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pybabel pybabel-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
