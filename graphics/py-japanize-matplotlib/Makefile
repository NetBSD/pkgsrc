# $NetBSD: Makefile,v 1.1 2025/01/04 16:33:55 ryoon Exp $

DISTNAME=	japanize-matplotlib-1.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/japanize-matplotlib/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://pypi.org/project/japanize-matplotlib/
COMMENT=	Japanese character support for matplotlib
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-matplotlib>=0:../../graphics/py-matplotlib

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
