# $NetBSD: Makefile,v 1.23 2022/01/04 20:53:37 wiz Exp $

DISTNAME=	ruamel.yaml-0.17.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1}
PKGREVISION=	1
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
