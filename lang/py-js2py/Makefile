# $NetBSD: Makefile,v 1.1 2017/02/07 23:50:27 joerg Exp $

DISTNAME=	Js2Py-0.43
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	python lang
MASTER_SITES=	${MASTER_SITE_PYPI:=J/Js2Py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/Js2Py/
COMMENT=	Python implementation of Javascript
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-jsparser-[0-9]*:../../lang/py-jsparser
DEPENDS+=	${PYPKGPREFIX}-tzlocal-[0-9]*:../../time/py-tzlocal

USE_LANGUAGES=	# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
