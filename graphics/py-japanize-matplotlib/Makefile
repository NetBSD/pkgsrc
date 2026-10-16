# $NetBSD: Makefile,v 1.6 2026/10/16 19:43:57 adam Exp $

DISTNAME=	japanize-matplotlib-1.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/japanize-matplotlib/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://pypi.org/project/japanize-matplotlib/
COMMENT=	Japanese character support for matplotlib
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=0:../../graphics/py-matplotlib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
