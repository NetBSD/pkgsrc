# $NetBSD: Makefile,v 1.11 2021/11/23 09:01:47 adam Exp $

DISTNAME=	simpleeval-0.9.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/simpleeval/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/danthedeckie/simpleeval
COMMENT=	Simple, safe single expression evaluator library
LICENSE=	mit

USE_LANGUAGES=	# none

PYSETUP=	-c 'from setuptools import setup; setup()'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
