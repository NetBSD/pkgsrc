# $NetBSD: Makefile,v 1.3 2004/07/25 12:27:46 wiz Exp $
#

DISTNAME=		NeoPop-SDL-0.2
CATEGORIES=		emulators
MASTER_SITES=		http://www.nih.at/NeoPop-SDL/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.nih.at/NeoPop-SDL/
COMMENT=		SNK NeoGeo Pocket emulator

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-png=${BUILDLINK_PREFIX.png}

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
