# $NetBSD: Makefile,v 1.3 2014/07/28 02:48:49 wen Exp $
#

DISTNAME=	pep8-1.5.7
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
