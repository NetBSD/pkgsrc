# $NetBSD: Makefile,v 1.12 2007/01/07 09:14:11 rillig Exp $
#

DISTNAME=	bbsload-0.2.6
PKGREVISION=	1
CATEGORIES=	sysutils x11 wm
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

MAINTAINER=	pino@dohd.org
HOMEPAGE=	http://bbtools.windsofstorm.net/
COMMENT=	Small (in dimensions) tool to display the average load

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_X11BASE=		YES

.include "../../mk/x11.buildlink3.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/bbsload.1 ${PREFIX}/${PKGMANDIR}/man1/bbsload.1

.include "../../mk/bsd.pkg.mk"
