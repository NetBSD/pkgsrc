# $NetBSD: Makefile,v 1.16 2021/04/21 15:26:50 wiz Exp $

DISTNAME=	tfkiss-1.2.4
PKGREVISION=	1
CATEGORIES=	ham
#MASTER_SITES=	ftp://ftp.ping.net.au/pub/unix/ham/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hamradio.ping.net.au/index.php?mode=tfkiss
COMMENT=	Software implementation of TheFirmware for use with TNT

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-xpid
CONFIGURE_ARGS+=	--enable-flexnet
CONFIGURE_ARGS+=	--enable-axip

.include "../../mk/bsd.pkg.mk"
