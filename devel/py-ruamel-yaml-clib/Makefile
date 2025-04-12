# $NetBSD: Makefile,v 1.12 2025/04/12 20:13:34 adam Exp $

DISTNAME=	ruamel.yaml.clib-0.2.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1:S/./-/1}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml.clib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yaml.readthedocs.io/
COMMENT=	C version of reader, parser and emitter for ruamel.yaml
LICENSE=	mit

WHEEL_NAME=	ruamel_yaml_clib-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

CFLAGS+=	-Wno-error=incompatible-pointer-types

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
