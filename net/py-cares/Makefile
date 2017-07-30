# $NetBSD: Makefile,v 1.3 2017/07/30 22:32:20 wiz Exp $

DISTNAME=	pycares-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycares/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/saghul/pycares
COMMENT=	Python interface for c-ares
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.5.0:../../devel/py-cffi

USE_LANGUAGES=		c
MAKE_ENV+=		PYCARES_CFFI=1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
