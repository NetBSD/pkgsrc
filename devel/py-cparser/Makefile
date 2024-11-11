# $NetBSD: Makefile,v 1.18 2024/11/11 07:28:05 wiz Exp $

DISTNAME=	pycparser-2.22
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
PKGREVISION=	1
CATEGORIES=	devel lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycparser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eliben/pycparser
COMMENT=	C parser in Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
