# $NetBSD: Makefile,v 1.10 2005/12/05 20:50:23 rillig Exp $
#

DISTNAME=	tfkiss-1.2.4
CATEGORIES=	ham
MASTER_SITES=	ftp://ftp.ping.net.au/pub/unix/ham/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://www.bfl.at/mayer/ham/
COMMENT=	Software implementation of TheFirmware for use with TNT

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-xpid
CONFIGURE_ARGS+=	--enable-flexnet
CONFIGURE_ARGS+=	--enable-axip

.include "../../mk/bsd.pkg.mk"
