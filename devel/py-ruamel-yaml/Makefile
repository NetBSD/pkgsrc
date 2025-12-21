# $NetBSD: Makefile,v 1.53 2025/12/21 16:34:13 wiz Exp $

DISTNAME=	ruamel_yaml-0.18.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/1}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yaml.dev/doc/ruamel.yaml/
COMMENT=	YAML parser/emitter
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/./}
#WHEEL_NAME=	${DISTNAME:S/./_/1}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml-clib>=0.2.7:../../devel/py-ruamel-yaml-clib

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
