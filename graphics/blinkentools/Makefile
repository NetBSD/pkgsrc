# $NetBSD: Makefile,v 1.26 2012/10/06 14:10:42 asau Exp $
#

DISTNAME=		blinkentools-2.2
PKGREVISION=		18
CATEGORIES=		graphics
MASTER_SITES=		http://sven.gimp.org/blinkenlights/old/

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.blinkenlights.de/
COMMENT=		Blinkenlights movies tools collection

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES

LDFLAGS.DragonFly=	-lz

CONFIGURE_ARGS+=	--enable-oldtools

.include "../../devel/blib/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
