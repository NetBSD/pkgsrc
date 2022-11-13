# $NetBSD: Makefile,v 1.13 2022/11/13 12:30:44 adam Exp $

DISTNAME=	pathspec-0.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pathspec/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cpburnz/python-path-specification
COMMENT=	Utility library for gitignore style pattern matching of file paths
LICENSE=	mpl-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
