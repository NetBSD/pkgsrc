# $NetBSD: Makefile,v 1.1 2013/12/31 17:59:08 rodent Exp $

DISTNAME=	greenlet-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/g/greenlet/
EXTRACT_SUFX=	.zip
FETCH_USING=	curl

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/python-greenlet/greenlet
COMMENT=	Lightweight in-process concurrent programming
LICENSE=	mit

USE_LANGUAGES=	c c++

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
