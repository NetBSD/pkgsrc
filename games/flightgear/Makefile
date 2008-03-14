# $NetBSD: Makefile,v 1.2 2008/03/14 14:49:53 drochner Exp $
#

DISTNAME=		FlightGear-1.0.0
PKGNAME=		${DISTNAME:S/FlightGear/flightgear/}
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.flightgear.org/pub/fgfs/Source/ \
			ftp://ftp.sunsite.org.uk/sites/ftp.flightgear.org/flightgear-ftp/Source/ \
			ftp://ftp.kingmont.com/flightsims/flightgear/Source/ \
			http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Source/ \
			ftp://ftp.de.flightgear.org/pub/fgfs/Source/ \
			ftp://obgyn.edu.pl/fgfs/Source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.flightgear.org/
COMMENT=		The FlightGear Simulator

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++

CONFIGURE_ARGS+=	--with-threads
CONFIGURE_ARGS+=	--enable-sdl
CFLAGS!=	sdl-config --cflags

.include "../../audio/openal/buildlink3.mk"
.include "../../audio/freealut/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../games/simgear/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
