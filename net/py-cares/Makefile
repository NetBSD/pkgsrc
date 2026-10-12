# $NetBSD: Makefile,v 1.22 2026/10/12 13:18:27 wiz Exp $

DISTNAME=	pycares-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycares/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/saghul/pycares
COMMENT=	Python interface for c-ares
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.5.0:../../devel/py-cffi

MAKE_ENV+=	PYCARES_USE_SYSTEM_LIB=1

.include "../../lang/python/wheel.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
