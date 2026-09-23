# $NetBSD: Makefile,v 1.12 2026/09/23 09:25:09 adam Exp $

DISTNAME=	python_slugify-9.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python_//}
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-slugify/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/un33k/python-slugify
COMMENT=	Slugify (non-ASCII to ASCII) application that handles Unicode
LICENSE=	mit

PREV_PKGPATH=	devel/py-python-slugify

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-text-unidecode>=1.3:../../textproc/py-text-unidecode

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	slugify

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
