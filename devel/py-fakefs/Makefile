# $NetBSD: Makefile,v 1.2 2019/02/17 08:36:33 adam Exp $

DISTNAME=	pyfakefs-3.5.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyfakefs/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://pyfakefs.org/
COMMENT=	Fake file system that mocks the Python file system modules
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
