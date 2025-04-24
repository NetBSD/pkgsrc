# $NetBSD: Makefile,v 1.3 2025/04/24 15:22:22 adam Exp $

DISTNAME=	brewer2mpl-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/brewer2mpl/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jiffyclub/brewer2mpl/wiki
COMMENT=	Connect colorbrewer2.org color maps to Python and matplotlib
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
