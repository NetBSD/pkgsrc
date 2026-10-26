# $NetBSD: Makefile,v 1.3 2026/10/26 06:11:54 wiz Exp $

DISTNAME=	bcrypt-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bcrypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/bcrypt
COMMENT=	Modern password hashing (non-Rust version)
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=84.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.1:../../devel/py-cffi

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
