# $NetBSD: Makefile,v 1.8 2024/04/30 13:21:43 wiz Exp $

PTTVERS=	1.19.6
DISTNAME=	twitter-${PTTVERS}
PKGNAME=	${PYPKGPREFIX}-ptt-${PTTVERS}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twitter/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://mike.verdone.ca/twitter/
COMMENT=	Twitter API, command-line tool, and IRC bot
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-irclib-[0-9]*:../../net/py-irclib
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
