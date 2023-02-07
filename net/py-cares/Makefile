# $NetBSD: Makefile,v 1.7 2023/02/07 10:55:56 adam Exp $

DISTNAME=	pycares-4.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycares/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/saghul/pycares
COMMENT=	Python interface for c-ares
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.5.0:../../devel/py-cffi

USE_LANGUAGES=	c
MAKE_ENV+=	PYCARES_CFFI=1

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
