# $NetBSD: Makefile,v 1.16 2025/04/12 10:59:18 adam Exp $

DISTNAME=	fasteners-0.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fasteners/}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/harlowja/fasteners
COMMENT=	Python package providing useful locks
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
