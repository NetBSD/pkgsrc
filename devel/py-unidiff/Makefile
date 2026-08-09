# $NetBSD: Makefile,v 1.2 2026/08/09 06:36:48 adam Exp $

DISTNAME=	python-unidiff-1.0.0
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=matiasb/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	python-unidiff

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/unidiff
COMMENT=	Unified diff python parsing/metadata extraction library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

WHEEL_NAME=	${DISTNAME:S/python-//}

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	unidiff

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
