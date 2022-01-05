# $NetBSD: Makefile,v 1.16 2022/01/05 15:41:16 wiz Exp $

DISTNAME=	gsutil-4.68
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gsutil/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://cloud.google.com/storage/docs/gsutil
COMMENT=	Command line tool for interacting with cloud storage services
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.13:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-argcomplete>=1.9.4:../../devel/py-argcomplete
DEPENDS+=	${PYPKGPREFIX}-crcmod>=1.7:../../security/py-crcmod
DEPENDS+=	${PYPKGPREFIX}-fasteners>=0.14.1:../../devel/py-fasteners
DEPENDS+=	${PYPKGPREFIX}-gcs-oauth2-boto-plugin>=2.7:../../net/py-gcs-oauth2-boto-plugin
DEPENDS+=	${PYPKGPREFIX}-google-apitools>=0.5.32:../../www/py-google-apitools
DEPENDS+=	${PYPKGPREFIX}-google-reauth>=0.1.0:../../security/py-google-reauth
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.18:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-monotonic>=1.4:../../time/py-monotonic
DEPENDS+=	${PYPKGPREFIX}-retry_decorator>=1.0.0:../../devel/py-retry_decorator
DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

REPLACE_PYTHON+=	gslib/vendored/boto/boto/pyami/launch_ami.py
REPLACE_PYTHON+=	gslib/vendored/boto/boto/services/bs.py
REPLACE_PYTHON+=	gslib/vendored/boto/tests/fps/test.py
REPLACE_PYTHON+=	gslib/vendored/boto/tests/test.py
REPLACE_PYTHON+=	gslib/vendored/oauth2client/samples/django/django_user/manage.py
REPLACE_PYTHON+=	gslib/vendored/oauth2client/samples/django/google_user/manage.py

CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/gslib/vendored/oauth2client/scripts/build_docs.sh
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/gslib/vendored/oauth2client/scripts/install.sh
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/gslib/vendored/oauth2client/scripts/run.sh
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/gslib/vendored/oauth2client/scripts/run_system_tests.sh

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} gsutil gsutil-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
