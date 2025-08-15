# $NetBSD: Makefile,v 1.1 2025/08/15 06:51:29 kim Exp $

DISTNAME=	userpath-1.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/userpath/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/userpath/
COMMENT=	Cross-platform tool for adding locations to the user PATH
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} userpath userpath${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
