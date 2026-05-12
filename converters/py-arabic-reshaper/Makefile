# $NetBSD: Makefile,v 1.8 2026/05/12 07:53:33 adam Exp $

DISTNAME=	arabic_reshaper-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/arabic-reshaper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mpcabd/python-arabic-reshaper
COMMENT=	Reconstruct Arabic sentences
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
