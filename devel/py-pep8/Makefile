# $NetBSD: Makefile,v 1.12 2023/04/30 14:33:51 wiz Exp $

DISTNAME=	pep8-1.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pep8/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://github.com/jcrocholl/pep8
COMMENT=	Python style guide checker (obsolete, use py-codestyle)
LICENSE=	mit

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} setup.py test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
