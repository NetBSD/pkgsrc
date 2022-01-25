# $NetBSD: Makefile,v 1.4 2022/01/25 09:05:11 wiz Exp $

DISTNAME=	inflect-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/inflect/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/inflect
COMMENT=	Correctly generate plurals, ordinals, indefinite articles for English
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools_scm:build

.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} < 38
PYTHON_VERSIONED_DEPENDENCIES+=	importlib-metadata
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
