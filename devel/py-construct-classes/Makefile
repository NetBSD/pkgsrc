# $NetBSD: Makefile,v 1.6 2026/09/08 11:51:30 adam Exp $

DISTNAME=	construct_classes-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/construct-classes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/matejcik/construct-classes
COMMENT=	Parse your binary structs into dataclasses
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.4:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-construct>=2.10:../../devel/py-construct

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
