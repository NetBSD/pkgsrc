# $NetBSD: Makefile,v 1.15 2025/03/08 12:33:38 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	39 310 313 # py-sphinx, py-Tempita

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
