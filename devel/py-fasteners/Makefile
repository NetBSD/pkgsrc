# $NetBSD: Makefile,v 1.15 2024/11/11 07:28:08 wiz Exp $

DISTNAME=	fasteners-0.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fasteners/}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/harlowja/fasteners
COMMENT=	Python package providing useful locks
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
