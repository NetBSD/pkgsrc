# $NetBSD: Makefile,v 1.1 2020/09/29 00:02:32 khorben Exp $

DISTNAME=	cytoolz-0.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cytoolz/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/pytoolz/cytoolz
COMMENT=	Cython Toolz High performance functional utilities
LICENSE=	modified-bsd

PYDISTUTILSPKG=	yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
