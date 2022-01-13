# $NetBSD: Makefile,v 1.3 2022/01/13 19:31:20 wiz Exp $

DISTNAME=	zopfli-0.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zopfli/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fonttools/py-zopfli
COMMENT=	Zopfli module for Python
LICENSE=	apache-2.0

PYTHON_VERSIONED_DEPENDENCIES=	setuptools_scm:build

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
