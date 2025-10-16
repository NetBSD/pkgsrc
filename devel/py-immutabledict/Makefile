# $NetBSD: Makefile,v 1.14 2025/10/16 14:48:00 adam Exp $

DISTNAME=	immutabledict-4.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/immutabledict/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/corenting/immutabledict
COMMENT=	Immutable wrapper around dictionaries for Python 3
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
