# $NetBSD: Makefile,v 1.11 2022/01/05 15:41:02 wiz Exp $

DISTNAME=	pycodestyle-2.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycodestyle/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://github.com/PyCQA/pycodestyle
COMMENT=	Python style guide checker
LICENSE=	mit

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pycodestyle pycodestyle-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m unittest -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
