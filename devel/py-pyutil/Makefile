# $NetBSD: Makefile,v 1.20 2018/07/03 05:03:12 adam Exp $

DISTNAME=	pyutil-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyutil/}

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	https://github.com/tpltnt/pyutil
COMMENT=	Collection of mature utilities for Python programmers
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.0:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-zbase32>=1.0:../../converters/py-zbase32
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.3.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted>=15.5.0:../../net/py-twisted

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-zbase32

post-extract:
	${FIND} ${WRKSRC} -name __pycache__ -or -name '*.pyc' -exec ${RM} -R {} +

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
