# $NetBSD: Makefile,v 1.2 2018/10/11 10:07:04 adam Exp $

DISTNAME=	asteval-0.9.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asteval/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/newville/asteval
COMMENT=	Safe, minimalistic expression evaluator using ast module
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.6:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
