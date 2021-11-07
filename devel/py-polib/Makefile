# $NetBSD: Makefile,v 1.6 2021/11/07 11:49:06 adam Exp $

DISTNAME=	polib-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/polib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/izimobil/polib
COMMENT=	Library to manipulate gettext files
LICENSE=	mit

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
