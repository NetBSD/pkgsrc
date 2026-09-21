# $NetBSD: Makefile,v 1.3 2026/09/21 18:46:28 adam Exp $

DISTNAME=	mpegdash-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	multimedia python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mpegdash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/caststack/python-mpegdash
COMMENT=	MPEG-DASH MPD(Media Presentation Description) Parser
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
