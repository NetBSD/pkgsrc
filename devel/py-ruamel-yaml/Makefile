# $NetBSD: Makefile,v 1.51 2025/08/20 09:50:28 adam Exp $

DISTNAME=	ruamel.yaml-0.18.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yaml.readthedocs.io/
COMMENT=	YAML parser/emitter
LICENSE=	mit

WHEEL_NAME=	${DISTNAME:S/./_/1}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml-clib>=0.2.7:../../devel/py-ruamel-yaml-clib

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
