# $NetBSD: Makefile,v 1.2 2018/01/14 11:19:04 adam Exp $

DISTNAME=	blessings-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blessings/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/erikrose/blessings
COMMENT=	Thin, practical wrapper around terminal
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
