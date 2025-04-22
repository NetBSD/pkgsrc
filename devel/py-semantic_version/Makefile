# $NetBSD: Makefile,v 1.10 2025/04/22 20:12:58 wiz Exp $

DISTNAME=	semantic_version-2.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/semantic_version/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rbarrois/python-semanticversion
COMMENT=	Semantic version comparison for Python
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
