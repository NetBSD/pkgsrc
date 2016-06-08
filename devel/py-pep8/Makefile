# $NetBSD: Makefile,v 1.5 2016/06/08 17:43:26 wiz Exp $
#

DISTNAME=	pep8-1.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pep8/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://github.com/jcrocholl/pep8
COMMENT=	Python style guide checker
LICENSE=	mit

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} setup.py test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
