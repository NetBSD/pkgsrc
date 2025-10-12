# $NetBSD: Makefile,v 1.1 2025/10/12 17:28:58 wiz Exp $

DISTNAME=	dunamai-1.25.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dunamai/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mtkennerly/dunamai
COMMENT=	Dynamic version generation
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core

USE_LANGUAGES=	# none
# for testing
USE_TOOLS+=	git

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
