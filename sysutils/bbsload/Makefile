# $NetBSD: Makefile,v 1.6 2004/04/18 23:19:46 snj Exp $
#

DISTNAME=	bbsload-0.2.6
CATEGORIES=	sysutils x11 wm
MASTER_SITES=	http://bbtools.thelinuxcommunity.org/sources/

MAINTAINER=	pino@dohd.org
HOMEPAGE=	http://bbtools.thelinuxcommunity.org/
COMMENT=	Small (in dimensions) tool to display the average load

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_X11BASE=		YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/bbsload.1 ${PREFIX}/man/man1/bbsload.1

.include "../../mk/bsd.pkg.mk"
