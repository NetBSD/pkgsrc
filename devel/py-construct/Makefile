# $NetBSD: Makefile,v 1.5 2017/06/21 09:53:50 adam Exp $

DISTNAME=	construct-2.8.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/construct/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://construct.readthedocs.io/
COMMENT=	Powerful declarative parser for binary data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
