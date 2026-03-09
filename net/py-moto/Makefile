# $NetBSD: Makefile,v 1.21 2026/03/09 08:52:01 adam Exp $

DISTNAME=	moto-5.1.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/moto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/getmoto/moto
COMMENT=	Mock-up of the boto library
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-boto3>=1.9.201:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-botocore>=1.35.47:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.5:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-responses>=0.25.6:../../net/py-responses
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=2.2.2:../../www/py-werkzeug
DEPENDS+=	${PYPKGPREFIX}-xmltodict-[0-9]*:../../textproc/py-xmltodict
# proxy
DEPENDS+=	${PYPKGPREFIX}-multipart-[0-9]*:../../www/py-multipart
# server
DEPENDS+=	${PYPKGPREFIX}-flask>=2.2.2:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-cors-[0-9]*:../../www/py-flask-cors
DEPENDS+=	${PYPKGPREFIX}-pyaml>=5.1:../../textproc/py-pyaml
# unlisted but used
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-openapi-spec-validator>=0.2.8:../../textproc/py-openapi-spec-validator
TEST_DEPENDS+=	${PYPKGPREFIX}-sure>=1.2.24:../../devel/py-sure
# not packaged
#TEST_DEPENDS+=	${PYPKGPREFIX}-docker-[0-9]*:../../devel/py-docker

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

post-install:
.for bin in moto_proxy moto_server
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
