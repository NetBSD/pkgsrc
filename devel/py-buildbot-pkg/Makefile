# $NetBSD: Makefile,v 1.15 2026/02/18 10:47:09 wiz Exp $

DISTNAME=	buildbot_pkg-${BBVERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot-pkg/}

COMMENT=	Packaging tools for the buildbot CI system

DEPENDS+=	${PYPKGPREFIX}-setuptools>=21.2.1:../../devel/py-setuptools

USE_LANGUAGES=	# none

# override default versioning based on time stamp
MAKE_ENV+=	BUILDBOT_VERSION=${PKGVERSION_NOREV}

.include "../../devel/py-buildbot/Makefile.common"
.include "../../mk/bsd.pkg.mk"
