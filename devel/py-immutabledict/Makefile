# $NetBSD: Makefile,v 1.10 2024/01/08 11:57:05 adam Exp $

DISTNAME=	immutabledict-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/immutabledict/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/corenting/immutabledict
COMMENT=	Immutable wrapper around dictionaries for Python 3
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
