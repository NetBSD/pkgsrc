# $NetBSD: Makefile,v 1.5 2018/04/11 13:24:02 adam Exp $

DISTNAME=	pycodestyle-2.4.0
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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
