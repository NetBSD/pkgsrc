# $NetBSD: Makefile,v 1.1 2017/04/12 11:42:45 adam Exp $

DISTNAME=	curtsies-0.2.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/curtsies/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thomasballinger/curtsies
COMMENT=	Curses-like terminal wrapper, with colored strings
LICENSE=	mit

USE_LANGUAGES=		# none

DEPENDS+=	${PYPKGPREFIX}-blessings-[0-9]*:../../devel/py-blessings
DEPENDS+=	${PYPKGPREFIX}-wcwidth-[0-9]*:../../devel/py-wcwidth

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
