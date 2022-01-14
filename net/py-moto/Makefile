# $NetBSD: Makefile,v 1.6 2022/01/14 09:37:36 wiz Exp $

DISTNAME=	moto-1.1.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/moto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spulec/moto
COMMENT=	Mock-up of the boto library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-boto>=2.36.0:../../net/py-boto
DEPENDS+=	${PYPKGPREFIX}-boto3>=1.2.1:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-cookies-[0-9]*:../../www/py-cookies
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.0.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-dicttoxml-[0-9]*:../../textproc/py-dicttoxml
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.8:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-pyaml-[0-9]*:../../textproc/py-pyaml
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.5:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.10:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug
DEPENDS+=	${PYPKGPREFIX}-xmltodict-[0-9]*:../../textproc/py-xmltodict

TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-gdbm-[0-9]*:../../databases/py-gdbm
TEST_DEPENDS+=	${PYPKGPREFIX}-lxml>=4.0.0:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-sure>=1.2.24:../../devel/py-sure
TEST_DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

USE_PKG_RESOURCES=	yes

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-sure

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} moto_server moto_server${PYVERSSUFFIX} || ${TRUE}

do-test:
	#cd ${WRKSRC}/tests && nosetests-${PYVERSSUFFIX}
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
