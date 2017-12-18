# $NetBSD: Makefile,v 1.1 2017/12/18 08:48:26 adam Exp $

DISTNAME=	clint-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/clint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kennethreitz/clint
COMMENT=	Python Command-line Application Tools
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-args-[0-9]*:../../devel/py-args

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
