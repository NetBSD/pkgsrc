# $NetBSD: Makefile,v 1.3 2017/12/18 12:13:56 adam Exp $

DISTNAME=	buildbot-pkg-0.9.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot-pkg/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://buildbot.net/
COMMENT=	Packaging tools for the buildbot CI system
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

# override default versioning based on time stamp
MAKE_ENV+=	BUILDBOT_VERSION=${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
