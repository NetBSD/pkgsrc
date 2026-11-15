# $NetBSD: Makefile,v 1.1 2026/11/15 21:22:16 wiz Exp $

DISTNAME=	beartype-0.23.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=b/beartype/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/beartype/beartype/
COMMENT=	The bare-mental type checker
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	# none

# as of 0.23.1
# 4 failed, 435 passed, 37 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
