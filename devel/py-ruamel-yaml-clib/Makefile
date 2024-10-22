# $NetBSD: Makefile,v 1.10 2024/10/22 11:09:03 adam Exp $

DISTNAME=	ruamel.yaml.clib-0.2.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1:S/./-/1}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml.clib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yaml.readthedocs.io/
COMMENT=	C version of reader, parser and emitter for ruamel.yaml
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

CFLAGS+=	-Wno-error=incompatible-pointer-types

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
