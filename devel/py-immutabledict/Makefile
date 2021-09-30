# $NetBSD: Makefile,v 1.3 2021/09/30 19:43:38 adam Exp $

DISTNAME=	immutabledict-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/immutabledict/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/corenting/immutabledict
COMMENT=	Immutable wrapper around dictionaries for Python 3
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
