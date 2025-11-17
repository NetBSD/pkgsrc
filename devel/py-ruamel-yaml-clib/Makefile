# $NetBSD: Makefile,v 1.14 2025/11/17 05:25:52 adam Exp $

DISTNAME=	ruamel_yaml_clib-0.2.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml.clib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yaml.dev/doc/ruamel.yaml.clib/
COMMENT=	C version of reader, parser and emitter for ruamel.yaml
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/./g}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

CFLAGS+=	-Wno-error=incompatible-pointer-types

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
