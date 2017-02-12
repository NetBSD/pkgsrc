# $NetBSD: Makefile,v 1.40 2017/02/12 06:25:24 ryoon Exp $
#

DISTNAME=		blinkentools-2.2
PKGREVISION=		32
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
