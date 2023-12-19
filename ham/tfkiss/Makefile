# $NetBSD: Makefile,v 1.17 2023/12/19 14:31:45 zafer Exp $

DISTNAME=	tfkiss-1.2.4
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	https://www.aydogan.net/distfiles/ham/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hamradio.ping.net.au/index.php?mode=tfkiss
COMMENT=	Software implementation of TheFirmware for use with TNT

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-xpid
CONFIGURE_ARGS+=	--enable-flexnet
CONFIGURE_ARGS+=	--enable-axip

.include "../../mk/bsd.pkg.mk"
