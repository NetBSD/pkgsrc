# $NetBSD: Makefile,v 1.8 2026/07/01 08:49:21 adam Exp $

DISTNAME=	polib-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/polib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/izimobil/polib
COMMENT=	Library to manipulate gettext files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
