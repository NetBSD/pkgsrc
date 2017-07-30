# $NetBSD: Makefile,v 1.4 2017/07/30 22:32:16 wiz Exp $

DISTNAME=	pycodestyle-2.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycodestyle/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://github.com/PyCQA/pycodestyle
COMMENT=	Python style guide checker
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pycodestyle pycodestyle-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} setup.py test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
