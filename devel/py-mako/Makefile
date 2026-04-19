# $NetBSD: Makefile,v 1.40 2026/04/19 17:19:19 wiz Exp $

DISTNAME=	mako-1.3.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Mako/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.makotemplates.org/
COMMENT=	Hyperfast and lightweight templating for the Python platform
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=0.9.2:../../textproc/py-markupsafe

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	mako-render

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
