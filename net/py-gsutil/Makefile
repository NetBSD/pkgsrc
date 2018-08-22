# $NetBSD: Makefile,v 1.4 2018/08/22 08:31:30 adam Exp $

DISTNAME=	gsutil-4.33
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gsutil/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://cloud.google.com/storage/docs/gsutil
COMMENT=	Command line tool for interacting with cloud storage services
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	27
REPLACE_PYTHON=			test/gsutil_measure_imports

DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-SocksiPy-branch>=1.01:../../net/py-socksipy-branch
DEPENDS+=	${PYPKGPREFIX}-argcomplete>=1.9.4:../../devel/py-argcomplete
DEPENDS+=	${PYPKGPREFIX}-boto>=2.48.0:../../net/py-boto
DEPENDS+=	${PYPKGPREFIX}-crcmod>=1.7:../../security/py-crcmod
DEPENDS+=	${PYPKGPREFIX}-fasteners>=0.14.1:../../devel/py-fasteners
DEPENDS+=	${PYPKGPREFIX}-gcs-oauth2-boto-plugin>=2.1:../../net/py-gcs-oauth2-boto-plugin
DEPENDS+=	${PYPKGPREFIX}-gflags>=3.1.2nb1:../../devel/py-gflags
DEPENDS+=	${PYPKGPREFIX}-google-apitools>=0.5.22:../../www/py-google-apitools
DEPENDS+=	${PYPKGPREFIX}-google-reauth>=0.1.0:../../security/py-google-reauth
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.11.3:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-monotonic>=1.4:../../time/py-monotonic
DEPENDS+=	${PYPKGPREFIX}-oauth2client>=4.1.2:../../security/py-oauth2client
DEPENDS+=	${PYPKGPREFIX}-retry_decorator>=1.0.0:../../devel/py-retry_decorator
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} gsutil gsutil-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
