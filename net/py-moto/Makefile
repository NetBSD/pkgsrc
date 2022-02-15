# $NetBSD: Makefile,v 1.7 2022/02/15 15:32:09 wiz Exp $

DISTNAME=	moto-3.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/moto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spulec/moto
COMMENT=	Mock-up of the boto library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-boto3>=1.9.201:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-botocore-[0-9]*:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.3.1:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-requests>=2.5:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-xmltodict-[0-9]*:../../textproc/py-xmltodict
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-responses>=0.9.0:../../net/py-responses
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10.1:../../textproc/py-jinja2
# unlisted but used
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-pyaml-[0-9]*:../../textproc/py-pyaml

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
# unlisted but used
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-sure>=1.2.24:../../devel/py-sure

USE_PKG_RESOURCES=	yes

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-sure

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} == "py37"
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} moto_server moto_server${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
