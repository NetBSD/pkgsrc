# $NetBSD: Makefile,v 1.13 2025/09/28 19:30:00 wiz Exp $

DISTNAME=	immutabledict-4.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
