# $NetBSD: Makefile,v 1.2 2021/02/07 19:27:27 adam Exp $

DISTNAME=	cytoolz-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cytoolz/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/pytoolz/cytoolz
COMMENT=	Cython Toolz High performance functional utilities
LICENSE=	modified-bsd

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
