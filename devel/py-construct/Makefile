# $NetBSD: Makefile,v 1.21 2024/11/11 07:28:04 wiz Exp $

DISTNAME=	construct-2.10.70
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/construct/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://construct.readthedocs.io/
COMMENT=	Powerful declarative parser for binary data
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
