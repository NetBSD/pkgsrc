# $NetBSD: Makefile,v 1.2 2025/04/14 05:08:08 adam Exp $

DISTNAME=	bcrypt-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bcrypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/bcrypt
COMMENT=	Modern password hashing (non-Rust version)
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.1:../../devel/py-cffi

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
