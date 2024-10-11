# $NetBSD: Makefile,v 1.9 2024/10/11 14:21:56 wiz Exp $

DISTNAME=	ruamel.yaml.clib-0.2.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1:S/./-/1}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml.clib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yaml.readthedocs.io/
COMMENT=	C version of reader, parser and emitter for ruamel.yaml
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

CFLAGS+=	-Wno-error=incompatible-pointer-types

# https://sourceforge.net/p/ruamel-yaml-clib/tickets/36/
#PYTHON_VERSIONS_INCOMPATIBLE=	313

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
