# $NetBSD: Makefile,v 1.2 2024/09/26 07:37:44 wiz Exp $

DISTNAME=	dep_logic-0.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dep-logic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/dep-logic
COMMENT=	Python dependency specifications supporting logical operations
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-packaging>=22:../../devel/py-packaging

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
