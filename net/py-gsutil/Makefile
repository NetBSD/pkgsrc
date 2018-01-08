# $NetBSD: Makefile,v 1.1 2018/01/08 19:01:20 bsiegert Exp $

DISTNAME=	gsutil-4.28
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gsutil/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://cloud.google.com/storage/docs/gsutil
COMMENT=	Command line tool for interacting with cloud storage services
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	27
REPLACE_PYTHON=			test/gsutil_measure_imports

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
