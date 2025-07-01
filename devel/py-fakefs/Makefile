# $NetBSD: Makefile,v 1.24 2025/07/01 15:17:45 adam Exp $

DISTNAME=	pyfakefs-5.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyfakefs/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/jmcgeheeiv/pyfakefs
COMMENT=	Fake file system that mocks the Python file system modules
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
