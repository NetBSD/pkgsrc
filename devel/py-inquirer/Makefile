# $NetBSD: Makefile,v 1.4 2023/08/30 21:46:33 js Exp $

DISTNAME=	PyInquirer-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-inquirer-1.0.3
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyInquirer/}

MAINTAINER=	js@NetBSD.org
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
