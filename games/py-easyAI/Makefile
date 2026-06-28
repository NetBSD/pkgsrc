# $NetBSD: Makefile,v 1.14 2026/06/28 15:41:20 wiz Exp $

DISTNAME=	easyAI-2.0.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/easyAI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zulko.github.io/easyAI/
COMMENT=	Easy-to-use game AI algorithms
LICENSE=	mit

WHEEL_NAME=	${DISTNAME:tl}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-numpy>0:../../math/py-numpy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
