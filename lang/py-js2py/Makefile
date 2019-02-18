# $NetBSD: Makefile,v 1.7 2019/02/18 12:57:21 adam Exp $

DISTNAME=	Js2Py-0.60
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=J/Js2Py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PiotrDabkowski/Js2Py
COMMENT=	Pure Python JavaScript Translator/Interpreter
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-jsparser>=2.5.1:../../lang/py-jsparser
DEPENDS+=	${PYPKGPREFIX}-six>=1.10:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=1.2:../../time/py-tzlocal

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
