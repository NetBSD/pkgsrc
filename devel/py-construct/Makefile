# $NetBSD: Makefile,v 1.3 2017/04/14 13:04:08 leot Exp $

DISTNAME=	construct-2.8.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/construct/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://construct.readthedocs.io/
COMMENT=	Powerful declarative parser for binary data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	c

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
