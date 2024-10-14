# $NetBSD: Makefile,v 1.13 2024/10/14 06:45:37 wiz Exp $

DISTNAME=	buildbot-console-view-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot-console-view/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://buildbot.net/
COMMENT=	Waterfall Plugin for the buildbot CI system
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-buildbot-[0-9]*:../../devel/py-buildbot
TOOL_DEPENDS+=	${PYPKGPREFIX}-buildbot-pkg-[0-9]*:../../devel/py-buildbot-pkg

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
