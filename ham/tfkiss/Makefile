# $NetBSD: Makefile,v 1.8 2004/01/24 13:40:43 grant Exp $
#

DISTNAME=	tfkiss-1.2.4
CATEGORIES=	ham
MASTER_SITES=	ftp://ftp.ping.net.au/pub/unix/ham/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://www.bfl.at/mayer/ham/
COMMENT=	Software implementation of TheFirmware for use with TNT

USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-xpid --enable-flexnet --enable-axip

.include "../../mk/bsd.pkg.mk"
