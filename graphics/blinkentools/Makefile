# $NetBSD: Makefile,v 1.1.1.1 2003/12/27 22:40:10 salo Exp $
#

DISTNAME=		blinkentools-2.2
CATEGORIES=		graphics
MASTER_SITES=		http://sven.gimp.org/blinkenlights/old/

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.blinkenlights.de/
COMMENT=		Blinkenlights movies tools collection

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-oldtools

.include "../../devel/blib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
