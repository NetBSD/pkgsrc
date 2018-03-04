# $NetBSD: Makefile,v 1.2 2018/03/04 12:11:21 bsiegert Exp $

DISTNAME=	gsutil-4.28
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gsutil/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://cloud.google.com/storage/docs/gsutil
COMMENT=	Command line tool for interacting with cloud storage services
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	27
REPLACE_PYTHON=			test/gsutil_measure_imports

DEPENDS+=	${PYPKGPREFIX}-argcomplete>=1.8:../../devel/py-argcomplete
DEPENDS+=	${PYPKGPREFIX}-boto-2.48.0*:../../net/py-boto
DEPENDS+=	${PYPKGPREFIX}-SocksiPy-branch-1.01*:../../net/py-socksipy-branch
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-retry_decorator>=1.1.0:../../devel/py-retry_decorator
DEPENDS+=	${PYPKGPREFIX}-gflags>=2:../../devel/py-gflags

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
