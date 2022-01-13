# $NetBSD: Makefile,v 1.8 2022/01/13 19:31:21 wiz Exp $

DISTNAME=	hgtools-6.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hgtools/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/hgtools
COMMENT=	Classes and setuptools plugin for Mercurial and Git repositories
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES=	setuptools_scm:build

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
