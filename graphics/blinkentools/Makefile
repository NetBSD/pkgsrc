# $NetBSD: Makefile,v 1.6 2005/07/21 16:29:50 wiz Exp $
#

DISTNAME=		blinkentools-2.2
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		http://sven.gimp.org/blinkenlights/old/

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.blinkenlights.de/
COMMENT=		Blinkenlights movies tools collection

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-oldtools

.include "../../devel/blib/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
