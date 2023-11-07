# $NetBSD: Makefile,v 1.12 2023/11/07 22:37:58 wiz Exp $

DISTNAME=	buildbot-waterfall-view-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot-waterfall-view/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://buildbot.net/
COMMENT=	Waterfall Plugin for the buildbot CI system
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-buildbot-[0-9]*:../../devel/py-buildbot
TOOL_DEPENDS+=	${PYPKGPREFIX}-buildbot-pkg-[0-9]*:../../devel/py-buildbot-pkg

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
