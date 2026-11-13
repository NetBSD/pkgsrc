# $NetBSD: Makefile,v 1.55 2026/11/13 09:50:56 adam Exp $

DISTNAME=	xdis-6.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xdis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rocky/python-xdis
COMMENT=	Python cross-version byte-code disassembler and marshal routines
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-click>=7.0.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pydisasm

# test status as of 6.1.8
# 1 error

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
