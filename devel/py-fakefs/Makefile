# $NetBSD: Makefile,v 1.10 2023/12/02 08:20:04 adam Exp $

DISTNAME=	pyfakefs-5.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyfakefs/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/jmcgeheeiv/pyfakefs
COMMENT=	Fake file system that mocks the Python file system modules
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
