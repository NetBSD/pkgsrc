# $NetBSD: Makefile,v 1.2 2016/06/01 12:30:45 wiz Exp $

DISTNAME=	construct-2.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/construct/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://pypi.python.org/pypi/construct
COMMENT=	Powerful declarative parser for binary data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	c

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
