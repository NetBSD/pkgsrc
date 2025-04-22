# $NetBSD: Makefile,v 1.10 2025/04/22 20:17:27 wiz Exp $

DISTNAME=	imagesize-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/imagesize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/shibukawa/imagesize_py
COMMENT=	Parses image files' header and returns image size
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

# as of 1.4.1
# 1 failed, 44 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
