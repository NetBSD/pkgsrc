# $NetBSD: Makefile,v 1.52 2026/05/22 12:47:29 adam Exp $

DISTNAME=	certifi-2026.5.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certifi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://certifi.io/
COMMENT=	Python package for providing Mozilla's CA Bundle
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
