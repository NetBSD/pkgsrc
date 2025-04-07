# $NetBSD: Makefile,v 1.43 2025/04/07 17:54:08 gdt Exp $

DISTNAME=	ruamel.yaml-0.18.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yaml.readthedocs.io/
COMMENT=	YAML parser/emitter
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml-clib>=0.2.7:../../devel/py-ruamel-yaml-clib

# The distfile uses '.'; the pkgsrc package uses '-'; the wheel uses '_'.
WHEEL_NAME=	${DISTNAME:S/./_/1}

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
