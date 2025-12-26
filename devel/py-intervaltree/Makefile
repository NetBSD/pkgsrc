# $NetBSD: Makefile,v 1.5 2025/12/26 10:17:57 adam Exp $

DISTNAME=	intervaltree-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/intervaltree/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/chaimleib/intervaltree
COMMENT=	Editable interval tree data structure
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.0:../../devel/py-sortedcontainers

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
