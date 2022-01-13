# $NetBSD: Makefile,v 1.5 2022/01/13 19:31:21 wiz Exp $

DISTNAME=	apipkg-1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/apipkg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/apipkg
COMMENT=	Namespace control and lazy-import mechanism
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES=	setuptools_scm:build

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
