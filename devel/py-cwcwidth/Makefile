# $NetBSD: Makefile,v 1.6 2022/11/15 09:12:11 adam Exp $

DISTNAME=	cwcwidth-0.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cwcwidth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sebastinas/cwcwidth
COMMENT=	Python bindings for wc(s)width
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
