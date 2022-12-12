# $NetBSD: Makefile,v 1.14 2022/12/12 13:44:59 adam Exp $

DISTNAME=	pathspec-0.10.3
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
