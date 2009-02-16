# $NetBSD: Makefile,v 1.12 2009/02/16 19:19:01 joerg Exp $
#

DISTNAME=	tfkiss-1.2.4
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	ftp://ftp.ping.net.au/pub/unix/ham/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://www.bfl.at/mayer/ham/
COMMENT=	Software implementation of TheFirmware for use with TNT

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-xpid
CONFIGURE_ARGS+=	--enable-flexnet
CONFIGURE_ARGS+=	--enable-axip

.include "../../mk/bsd.pkg.mk"
