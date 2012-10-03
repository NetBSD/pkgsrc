# $NetBSD: Makefile,v 1.14 2012/10/03 12:55:09 asau Exp $
#

DISTNAME=		NeoPop-SDL-0.2
PKGREVISION=		8
CATEGORIES=		emulators
MASTER_SITES=		http://www.nih.at/NeoPop-SDL/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.nih.at/NeoPop-SDL/
COMMENT=		SNK NeoGeo Pocket emulator

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-png=${BUILDLINK_PREFIX.png}

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
