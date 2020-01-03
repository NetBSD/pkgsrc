# $NetBSD: Makefile,v 1.6 2020/01/03 12:37:53 adam Exp $

DISTNAME=	pyfakefs-3.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyfakefs/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/jmcgeheeiv/pyfakefs
COMMENT=	Fake file system that mocks the Python file system modules
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
