# $NetBSD: Makefile,v 1.2 2004/04/12 01:58:50 snj Exp $
#

DISTNAME=		NeoPop-SDL-0.1
CATEGORIES=		emulators
MASTER_SITES=		http://www.nih.at/NeoPop-SDL/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.nih.at/NeoPop-SDL/
COMMENT=		SNK NeoGeo Pocket emulator

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-png=${BUILDLINK_PREFIX.png}

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
