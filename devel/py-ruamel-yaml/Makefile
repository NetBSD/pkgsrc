# $NetBSD: Makefile,v 1.24 2022/02/12 17:55:10 adam Exp $

DISTNAME=	ruamel.yaml-0.17.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/p/ruamel-yaml/
COMMENT=	YAML parser/emitter
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml-clib>=0.1.2:../../devel/py-ruamel-yaml-clib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
