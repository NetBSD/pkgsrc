# $NetBSD: Makefile,v 1.82 2019/02/16 13:26:49 wiz Exp $

DISTNAME=	flightgear-2018.2.2
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flightgear/release-2018.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.flightgear.org/
COMMENT=	The FlightGear Simulator
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_CMAKE=		yes
LDFLAGS.NetBSD+=	-lexecinfo

BUILDLINK_TRANSFORM+=	l:glut:freeglut

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
BUILDLINK_API_DEPENDS.simgear+=	simgear>=2.0.0
.include "../../games/simgear/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/osg/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
