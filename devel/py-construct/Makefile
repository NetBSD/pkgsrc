# $NetBSD: Makefile,v 1.6 2017/08/31 08:52:53 adam Exp $

DISTNAME=	construct-2.8.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/construct/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://construct.readthedocs.io/
COMMENT=	Powerful declarative parser for binary data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
