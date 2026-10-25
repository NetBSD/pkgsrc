# $NetBSD: Makefile,v 1.25 2026/10/25 17:51:44 wiz Exp $

DISTNAME=	pycares-5.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycares/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/saghul/pycares
COMMENT=	Python interface for c-ares
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=84.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=2.0.0:../../devel/py-cffi

MAKE_ENV+=	PYCARES_USE_SYSTEM_LIB=1

.include "../../lang/python/wheel.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
