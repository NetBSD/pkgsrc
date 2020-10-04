# $NetBSD: Makefile,v 1.1 2020/10/04 11:19:02 js Exp $

DISTNAME=	PyInquirer-1.0.3
PKGNAME=	${PYPKGPREFIX}-inquirer
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/CITGuru/PyInquirer/
COMMENT=	Collection of common interactive command line user interfaces
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=1.0.14:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.2.0:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-regex>=2016.11.21:../../textproc/py-regex

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# Untested

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
