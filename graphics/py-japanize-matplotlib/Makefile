# $NetBSD: Makefile,v 1.5 2026/06/28 15:41:24 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
