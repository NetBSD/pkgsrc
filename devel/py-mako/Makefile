# $NetBSD: Makefile,v 1.43 2026/09/28 15:37:03 wiz Exp $

DISTNAME=	mako-1.4.3
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
