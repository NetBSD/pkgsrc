# $NetBSD: Makefile,v 1.2 2018/12/22 17:24:20 taca Exp $

DISTNAME=	tqdm-4.23.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tqdm/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/tqdm/tqdm
COMMENT=	Fast, extensible progress bar for Python
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-mccabe-[0-9]*:../../devel/py-mccabe

USE_LANGUAGES=	# none

# for UTF-8 in README.md
ALL_ENV+=	LC_CTYPE=en_US.UTF-8
ALL_ENV+=	LC_ALL=en_US.UTF-8

.include "../../lang/python/egg.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/tqdm \
		${DESTDIR}${PREFIX}/bin/tqdm${PYVERSSUFFIX}

.include "../../mk/bsd.pkg.mk"
