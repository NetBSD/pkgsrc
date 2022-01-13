# $NetBSD: Makefile,v 1.4 2022/01/13 19:31:24 wiz Exp $

DISTNAME=	setuptools_scm_git_archive-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools_scm_git_archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Changaco/setuptools_scm_git_archive
COMMENT=	Setuptools_scm plugin for git archives
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES=	setuptools_scm:build

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
