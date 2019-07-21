# $NetBSD: Makefile,v 1.46 2019/07/21 22:24:55 wiz Exp $
#

DISTNAME=		blinkentools-2.2
PKGREVISION=		37
CATEGORIES=		graphics
MASTER_SITES=		http://sven.gimp.org/blinkenlights/old/

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.blinkenlights.de/
COMMENT=		Blinkenlights movies tools collection
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES

LDFLAGS.DragonFly=	-lz

CONFIGURE_ARGS+=	--enable-oldtools

.include "../../devel/blib/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
