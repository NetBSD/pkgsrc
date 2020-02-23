# $NetBSD: Makefile,v 1.11 2020/02/23 23:56:49 joerg Exp $

DISTNAME=	buildbot-www-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot-www/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://buildbot.net/
COMMENT=	Web frontend for the buildbot CI system
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-buildbot-[0-9]*:../../devel/py-buildbot
BUILD_DEPENDS+=	${PYPKGPREFIX}-buildbot-pkg-[0-9]*:../../devel/py-buildbot-pkg
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
