# $NetBSD: Makefile,v 1.8 2005/04/11 21:47:22 tv Exp $
#

DISTNAME=	bbsload-0.2.6
CATEGORIES=	sysutils x11 wm
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

MAINTAINER=	pino@dohd.org
HOMEPAGE=	http://bbtools.windsofstorm.net/
COMMENT=	Small (in dimensions) tool to display the average load

GNU_CONFIGURE=		YES
USE_X11BASE=		YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/bbsload.1 ${PREFIX}/man/man1/bbsload.1

.include "../../mk/bsd.pkg.mk"
