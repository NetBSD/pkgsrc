# $NetBSD: Makefile,v 1.11 2025/04/12 11:33:33 adam Exp $

DISTNAME=	kaitaistruct-0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kaitaistruct/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kaitai.io/
COMMENT=	Kaitai Struct declarative parser generator for binary data
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
