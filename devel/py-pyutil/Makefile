# $NetBSD: Makefile,v 1.22 2019/08/26 13:47:24 adam Exp $

DISTNAME=	pyutil-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyutil/}

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	https://github.com/tpltnt/pyutil
COMMENT=	Collection of mature utilities for Python programmers
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.0:../../converters/py-simplejson
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.3.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted>=15.5.0:../../net/py-twisted

USE_LANGUAGES=	# none

post-extract:
	${FIND} ${WRKSRC} -name __pycache__ -or -name '*.pyc' -exec ${RM} -R {} +

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
