# $NetBSD: Makefile,v 1.7 2022/01/04 20:53:21 wiz Exp $

DISTNAME=	polib-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
