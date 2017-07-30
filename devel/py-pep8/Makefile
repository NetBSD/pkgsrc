# $NetBSD: Makefile,v 1.8 2017/07/30 22:32:16 wiz Exp $

DISTNAME=	pep8-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pep8/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://github.com/jcrocholl/pep8
COMMENT=	Python style guide checker (obsolete, use py-codestyle)
LICENSE=	mit

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} setup.py test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
