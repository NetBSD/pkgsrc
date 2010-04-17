# $NetBSD: Makefile,v 1.9 2010/04/17 16:01:56 zafer Exp $
#

DISTNAME=		FlightGear-1.0.0
PKGNAME=		${DISTNAME:S/FlightGear/flightgear/}
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.flightgear.org/pub/fgfs/Source/ \
			http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.flightgear.org/
COMMENT=		The FlightGear Simulator

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++

CONFIGURE_ARGS+=	--with-threads
CONFIGURE_ARGS+=	--enable-sdl
CFLAGS+=		-I${LOCALBASE}/include/SDL

.include "../../audio/openal/buildlink3.mk"
.include "../../audio/freealut/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../games/simgear/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
