# $NetBSD: Makefile,v 1.25 2021/11/22 09:49:38 schmonz Exp $

DISTNAME=	approvaltests-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/approvaltests/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://approvaltests.com/
COMMENT=	Assertion/verification library to aid testing
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-pyperclip>=1.5.27:../../x11/py-pyperclip

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	test
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
