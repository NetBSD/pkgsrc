# $NetBSD: Makefile,v 1.7 2026/11/24 17:20:18 adam Exp $

DISTNAME=	unittest2pytest-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/unittest2pytest/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/unittest2pytest
COMMENT=	Tool to rewrite Python unittest into pytest test cases
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-fissix>=0:../../misc/py-fissix

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	unittest2pytest

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
