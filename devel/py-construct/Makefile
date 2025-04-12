# $NetBSD: Makefile,v 1.22 2025/04/12 09:54:04 adam Exp $

DISTNAME=	construct-2.10.70
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/construct/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://construct.readthedocs.io/
COMMENT=	Powerful declarative parser for binary data
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
