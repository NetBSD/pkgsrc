# $NetBSD: Makefile,v 1.2 2016/07/09 13:03:36 wiz Exp $
#

DISTNAME=	whisper-0.9.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
GITHUB_PROJECT= whisper
MASTER_SITES=	${MASTER_SITE_GITHUB:=graphite-project/}

MAINTAINER=	riz@NetBSD.org
HOMEPAGE=	https://launchpad.net/graphite
COMMENT=	Fixed-size database, similar in design to RRD
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
