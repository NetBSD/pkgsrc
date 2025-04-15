# $NetBSD: Makefile,v 1.10 2025/04/15 09:51:03 adam Exp $

PTTVERS=	1.19.6
DISTNAME=	twitter-${PTTVERS}
PKGNAME=	${PYPKGPREFIX}-ptt-${PTTVERS}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twitter/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://mike.verdone.ca/twitter/
COMMENT=	Twitter API, command-line tool, and IRC bot
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-irclib-[0-9]*:../../net/py-irclib
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
