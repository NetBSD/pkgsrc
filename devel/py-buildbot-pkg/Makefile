# $NetBSD: Makefile,v 1.11 2022/11/09 13:14:09 joerg Exp $

DISTNAME=	buildbot-pkg-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot-pkg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://buildbot.net/
COMMENT=	Packaging tools for the buildbot CI system
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

# override default versioning based on time stamp
MAKE_ENV+=	BUILDBOT_VERSION=${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
