# $NetBSD: Makefile,v 1.1 2026/11/02 10:20:50 adam Exp $

DISTNAME=	ckzg-2.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/ckzg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/c-kzg-4844
COMMENT=	Python bindings for C-KZG-4844
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_TOOLS+=	gmake

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
