# $NetBSD: Makefile,v 1.1 2015/12/11 21:34:15 riz Exp $
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

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
