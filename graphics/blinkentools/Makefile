# $NetBSD: Makefile,v 1.3 2004/04/15 13:07:55 wiz Exp $
#

DISTNAME=		blinkentools-2.2
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://sven.gimp.org/blinkenlights/old/

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.blinkenlights.de/
COMMENT=		Blinkenlights movies tools collection

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-oldtools

.include "../../devel/blib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
