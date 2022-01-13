# $NetBSD: Makefile,v 1.4 2022/01/13 19:31:23 wiz Exp $

DISTNAME=	iniconfig-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/iniconfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/RonnyPfannschmidt/iniconfig
COMMENT=	Brain-dead simple config-ini parsing
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES=	setuptools_scm:build

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
