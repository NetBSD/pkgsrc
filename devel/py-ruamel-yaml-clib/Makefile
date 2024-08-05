# $NetBSD: Makefile,v 1.8 2024/08/05 12:10:00 tnn Exp $

DISTNAME=	ruamel.yaml.clib-0.2.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1:S/./-/1}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml.clib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yaml.readthedocs.io/
COMMENT=	C version of reader, parser and emitter for ruamel.yaml
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

CFLAGS+=	-Wno-error=incompatible-pointer-types

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
