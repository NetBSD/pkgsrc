# $NetBSD: Makefile,v 1.7 2020/05/12 06:36:42 adam Exp $

DISTNAME=	pycodestyle-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycodestyle/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://github.com/PyCQA/pycodestyle
COMMENT=	Python style guide checker
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pycodestyle pycodestyle-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m unittest -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
