# $NetBSD: Makefile,v 1.75 2018/09/02 21:32:41 wiz Exp $

DISTNAME=	simgear-2018.2.2
PKGREVISION=	3
CATEGORIES=	games devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flightgear/release-2018.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.flightgear.org/
COMMENT=	Simulator Construction Tools
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_CMAKE=		yes

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/osg/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
