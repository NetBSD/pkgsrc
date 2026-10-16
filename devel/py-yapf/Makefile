# $NetBSD: Makefile,v 1.15 2026/10/16 18:16:49 adam Exp $

DISTNAME=	yapf-0.43.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yapf/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/google/yapf
COMMENT=	Python files formatter
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=3.5.1:../../misc/py-platformdirs

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	yapf yapf-diff

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
