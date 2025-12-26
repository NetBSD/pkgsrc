# $NetBSD: Makefile,v 1.13 2025/12/26 19:44:53 adam Exp $

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

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
