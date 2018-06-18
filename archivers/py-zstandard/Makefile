# $NetBSD: Makefile,v 1.6 2018/06/18 10:45:32 adam Exp $

DISTNAME=	zstandard-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zstandard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/indygreg/python-zstandard
COMMENT=	Zstandard bindings for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.11:../../devel/py-cffi

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
