# $NetBSD: Makefile,v 1.2 2017/07/11 19:36:40 adam Exp $

DISTNAME=	Js2Py-0.44
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	python lang
MASTER_SITES=	${MASTER_SITE_PYPI:=J/Js2Py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/Js2Py/
COMMENT=	Python implementation of Javascript
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-jsparser>=2.4.5:../../lang/py-jsparser
DEPENDS+=	${PYPKGPREFIX}-six>=1.10:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=1.2:../../time/py-tzlocal

USE_LANGUAGES=	# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
