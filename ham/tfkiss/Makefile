# $NetBSD: Makefile,v 1.9 2005/05/22 20:08:08 jlam Exp $
#

DISTNAME=	tfkiss-1.2.4
CATEGORIES=	ham
MASTER_SITES=	ftp://ftp.ping.net.au/pub/unix/ham/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://www.bfl.at/mayer/ham/
COMMENT=	Software implementation of TheFirmware for use with TNT

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-xpid --enable-flexnet --enable-axip

.include "../../mk/bsd.pkg.mk"
