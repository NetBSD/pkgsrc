# $NetBSD: Makefile,v 1.18 2026/02/18 10:47:08 wiz Exp $

DISTNAME=	buildbot_console_view-${BBVERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot-console-view/}

COMMENT=	Waterfall Plugin for the buildbot CI system

TOOL_DEPENDS+=	${PYPKGPREFIX}-buildbot-pkg-[0-9]*:../../devel/py-buildbot-pkg
DEPENDS+=	${PYPKGPREFIX}-buildbot-[0-9]*:../../devel/py-buildbot

USE_LANGUAGES=	# none

.include "../../devel/py-buildbot/Makefile.common"
.include "../../mk/bsd.pkg.mk"
