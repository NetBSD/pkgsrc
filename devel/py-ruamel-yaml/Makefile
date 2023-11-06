# $NetBSD: Makefile,v 1.36 2023/11/06 19:56:21 wiz Exp $

DISTNAME=	ruamel.yaml-0.18.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yaml.readthedocs.io/
COMMENT=	YAML parser/emitter
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml-clib>=0.2.7:../../devel/py-ruamel-yaml-clib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
