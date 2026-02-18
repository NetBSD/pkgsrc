# $NetBSD: Makefile,v 1.22 2026/02/18 10:47:09 wiz Exp $

DISTNAME=	buildbot_www-${BBVERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot-www/}

COMMENT=	Web frontend for the buildbot CI system

TOOL_DEPENDS+=	${PYPKGPREFIX}-buildbot-pkg-[0-9]*:../../devel/py-buildbot-pkg
DEPENDS+=	${PYPKGPREFIX}-buildbot-[0-9]*:../../devel/py-buildbot

USE_LANGUAGES=	# none

.include "../../devel/py-buildbot/Makefile.common"
.include "../../mk/bsd.pkg.mk"
