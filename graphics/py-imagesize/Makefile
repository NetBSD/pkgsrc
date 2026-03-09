# $NetBSD: Makefile,v 1.11 2026/03/09 17:04:50 wiz Exp $

DISTNAME=	imagesize-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/imagesize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/shibukawa/imagesize_py
COMMENT=	Parses image files' header and returns image size
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

# as of 2.0.0
# 1 failed, 81 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
