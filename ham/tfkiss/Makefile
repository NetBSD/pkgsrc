# $NetBSD: Makefile,v 1.13 2011/02/28 14:52:52 wiz Exp $
#

DISTNAME=	tfkiss-1.2.4
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	ftp://ftp.ping.net.au/pub/unix/ham/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bfl.at/mayer/ham/
COMMENT=	Software implementation of TheFirmware for use with TNT

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-xpid
CONFIGURE_ARGS+=	--enable-flexnet
CONFIGURE_ARGS+=	--enable-axip

.include "../../mk/bsd.pkg.mk"
