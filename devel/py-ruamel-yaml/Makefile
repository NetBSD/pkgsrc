# $NetBSD: Makefile,v 1.54 2026/01/04 14:45:30 adam Exp $

DISTNAME=	ruamel_yaml-0.19.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/1}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yaml.dev/doc/ruamel.yaml/
COMMENT=	YAML parser/emitter
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/./}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
