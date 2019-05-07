# $NetBSD: Makefile,v 1.3 2019/05/07 09:42:33 adam Exp $

DISTNAME=	curtsies-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/curtsies/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thomasballinger/curtsies
COMMENT=	Curses-like terminal wrapper, with colored strings
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-blessings-[0-9]*:../../devel/py-blessings
DEPENDS+=	${PYPKGPREFIX}-wcwidth-[0-9]*:../../devel/py-wcwidth

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
