# $NetBSD: Makefile,v 1.12 2009/08/26 19:57:36 sno Exp $
#

DISTNAME=		blinkentools-2.2
PKGREVISION=		6
CATEGORIES=		graphics
MASTER_SITES=		http://sven.gimp.org/blinkenlights/old/

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.blinkenlights.de/
COMMENT=		Blinkenlights movies tools collection

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-oldtools

.include "../../devel/blib/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
