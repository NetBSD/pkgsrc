# $NetBSD: Makefile,v 1.23 2012/09/07 19:16:36 adam Exp $

DISTNAME=	FlightGear-2.0.0
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	11
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Source/ \
		http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Source/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.flightgear.org/
COMMENT=	The FlightGear Simulator
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-sdl
CONFIGURE_ARGS+=	--with-threads

.include "../../audio/freealut/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
BUILDLINK_API_DEPENDS.simgear+=	simgear>=2.0.0
.include "../../games/simgear/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/osg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
