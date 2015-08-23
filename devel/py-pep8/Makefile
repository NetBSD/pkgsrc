# $NetBSD: Makefile,v 1.4 2015/08/23 11:26:38 wen Exp $
#

DISTNAME=	pep8-1.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pep8/

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://github.com/jcrocholl/pep8
COMMENT=	Python style guide checker
LICENSE=	mit

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} setup.py test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
