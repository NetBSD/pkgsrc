# $NetBSD: Makefile,v 1.17 2025/11/29 17:48:41 adam Exp $

DISTNAME=	atpublic-7.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/atpublic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://public.readthedocs.io/
COMMENT=	@public decorator for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-sybil-[0-9]*:../../devel/py-sybil

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
