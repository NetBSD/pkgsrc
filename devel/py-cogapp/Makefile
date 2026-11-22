# $NetBSD: Makefile,v 1.8 2026/11/22 19:03:29 wiz Exp $

DISTNAME=	cogapp-3.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cogapp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nedbatchelder.com/code/cog
COMMENT=	Code generator for executing Python snippets in source files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80:../../devel/py-setuptools

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	cog

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
