# $NetBSD: Makefile,v 1.8 2023/07/24 18:57:50 wiz Exp $

DISTNAME=	multipledispatch-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/multipledispatch/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/mrocklin/multipledispatch
COMMENT=	Efficient, mostly complete implementation of multiple dispatch
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
