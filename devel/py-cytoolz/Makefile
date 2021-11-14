# $NetBSD: Makefile,v 1.3 2021/11/14 18:50:54 adam Exp $

DISTNAME=	cytoolz-0.11.2
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
