# $NetBSD: Makefile,v 1.5 2020/01/26 17:31:54 rillig Exp $
#

PTTVERS=	1.9.0
DISTNAME=	twitter-${PTTVERS}
PKGNAME=	${PYPKGPREFIX}-ptt-${PTTVERS}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twitter/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://mike.verdone.ca/twitter/
COMMENT=	Twitter API, command-line tool, and IRC bot
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

.include "../../net/py-irclib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
