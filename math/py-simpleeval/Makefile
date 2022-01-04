# $NetBSD: Makefile,v 1.12 2022/01/04 20:54:17 wiz Exp $

DISTNAME=	simpleeval-0.9.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
