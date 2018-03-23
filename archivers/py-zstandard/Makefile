# $NetBSD: Makefile,v 1.4 2018/03/23 13:42:59 adam Exp $

DISTNAME=	zstandard-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zstandard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/indygreg/python-zstandard
COMMENT=	Zstandard bindings for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.8:../../devel/py-cffi

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
