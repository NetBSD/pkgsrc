# $NetBSD: Makefile,v 1.2 2012/11/03 14:29:25 imil Exp $
#

PTTVERS=	1.9.0
DISTNAME=	twitter-${PTTVERS}
PKGNAME=	${PYPKGPREFIX}-ptt-${PTTVERS}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	http://pypi.python.org/packages/source/t/twitter/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://mike.verdone.ca/twitter/
COMMENT=	Twitter API, command-line tool, and IRC bot
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../net/py-irclib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
