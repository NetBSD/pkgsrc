# $NetBSD: Makefile,v 1.5 2025/11/26 11:44:12 adam Exp $

DISTNAME=	construct_classes-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/construct-classes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/matejcik/construct-classes
COMMENT=	Parse your binary structs into dataclasses
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.8.13:../../devel/py-uv-build
DEPENDS+=	${PYPKGPREFIX}-construct>=2.10:../../devel/py-construct

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
