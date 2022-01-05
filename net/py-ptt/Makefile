# $NetBSD: Makefile,v 1.7 2022/01/05 15:41:17 wiz Exp $

PTTVERS=	1.9.0
DISTNAME=	twitter-${PTTVERS}
PKGNAME=	${PYPKGPREFIX}-ptt-${PTTVERS}
PKGREVISION=	3
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twitter/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://mike.verdone.ca/twitter/
COMMENT=	Twitter API, command-line tool, and IRC bot
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

.include "../../net/py-irclib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
